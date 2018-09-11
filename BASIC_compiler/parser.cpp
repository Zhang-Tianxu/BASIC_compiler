/*
* File: parser.cpp
* ----------------------
* This file is the implementation for
* the precedenec-based expression parser
*
*/

#include <stack>

#include "parser.h"
#include "exp.h"
#include "statement.h"

Statement* parseStatement(TokenScanner & scanner) {
	if (scanner.getFirstToken() == "LIST")
	{
		return new ListStmt();
	}
	else if (scanner.getFirstToken() == "CLEAR")
	{
		return new ClearStmt();
	}
	else if (scanner.getFirstToken() == "HELP")
	{
		return new HelpStmt();
	}
	else if (scanner.getFirstToken() == "RUN")
	{
		return new RunStmt();;
	}
	else if (scanner.getFirstToken() == "QUIT")
	{
		return new QuitStmt();

	}
	else
	{
		return NULL;//throw error
	}
}



//**********************************************
bool isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#')
		return true;
	else
		return false;
}
int getIndex(char opt) {
	int index = -1;
	switch (opt)
	{
	case '+':
	{
				index = 0;
				break;
	}
	case '-':
	{
				index = 1;
				break;
	}
	case '*':
	{
				index = 2;
				break;
	}
	case '/':
	{
				index = 3;
				break;
	}
	case '<':
	{
				index = 4;
				break;
	}
	case '>':
	{
				index = 5;
				break;
	}
	case '#':
	{
				index = 6;
				break;
	}
	default:
		break;
	}
	return index;
}



char getPriority(char opt1, char opt2) {
	const char priority[][7] =     //算符间的优先级关系
	{
		{ '>', '>', '<', '<', '<', '>', '>' },
		{ '>', '>', '<', '<', '<', '>', '>' },
		{ '>', '>', '>', '>', '<', '>', '>' },
		{ '>', '>', '>', '>', '<', '>', '>' },
		{ '<', '<', '<', '<', '<', '=', '0' },
		{ '>', '>', '>', '>', '0', '>', '>' },
		{ '<', '<', '<', '<', '<', '0', '=' },
	};
	return priority[getIndex(opt1)][getIndex(opt2)];
}


int calculate(int b, char opt, int a)   //计算b opt a
{
	switch (opt)
	{
	case '+':
		return b + a;
	case '-':
		return b - a;
	case '*':
		return b * a;
	case '/':
		return b / a;
	default:
		break;
	}
}


int parseExp(std::string line,EvalState & state) {
	line.push_back('#');
	std::stack<VarOrDigit> varStack;//变量开头不能是数字，若是数字表示这是一个常数
	std::stack<char> operatorStack;
	operatorStack.push('#');
	int i = 0;
	int len = line.size();
	VarOrDigit tmp;
	
	while (line[i] != '#' || operatorStack.top() != '#')
	{
		if (isOperator(line[i]))
		{
			if (tmp.getType() != UNKNOW)
			{
				varStack.push(tmp);
				tmp.clear();
			}
			else
			{
				//这是算符连续出现，或者出现在首位的情况。
			}


			char priority = getPriority(operatorStack.top(), line[i]);
			switch (priority)
			{
			case '<':
			{
						operatorStack.push(line[i++]);
						break;
			}
			case '=':
			{
						operatorStack.pop();
						i++;
						break;
			}
			case '>':
			{
						int num1, num2;
						if (varStack.top().getType() == DIGIT)
						{
							num1 = stoi(varStack.top().getContent());
							varStack.pop();
						}
						else
						{
							num1 = state.getValue(varStack.top().getContent());
							varStack.pop();
						}
						if (varStack.top().getType() == DIGIT)
						{
							num2 = stoi(varStack.top().getContent());
							varStack.pop();
						}
						else
						{
							num2 = state.getValue(varStack.top().getContent());
							varStack.pop();
						}
						std::cout << "num1 = " << num1 << std::endl;
						std::cout << "num2 = " << num2 << std::endl;

						std::cout << "calculated result is " << calculate(num2, operatorStack.top(), num1) << std::endl;
						std::cout << "calculated result is " << std::to_string(calculate(num2, operatorStack.top(), num1)) << std::endl;
						VarOrDigit tmp1;
						tmp1.setContent(std::to_string(calculate(num2, operatorStack.top(), num1)));
						tmp1.setType(DIGIT);
						operatorStack.pop();
						varStack.push(tmp1);
						break;
			}
			default:
				break;
			}
			//operatorStack.push(line[i++]);
		}
		else
		{
			if (isdigit(line[i]) && tmp.getType() == UNKNOW)
			{
				tmp.addContentC(line[i++]);
				tmp.setType(DIGIT);

			}
			else if (isdigit(line[i]))
			{
				tmp.addContentC(line[i++]);
			}
			else if (tmp.getType() == UNKNOW)
			{
				tmp.addContentC(line[i++]);
				tmp.setType(VARIABLE);
				//error
			}
			else if (tmp.getType() == VARIABLE)
			{
				tmp.addContentC(line[i++]);
			}
			else
			{
				//error
			}
		}
	}
	if (i+1 == len)//i == len -1?
	{
		return stoi(varStack.top().getContent());
	}
	else
	{
		//error
	}
}