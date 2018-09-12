/*
 * File: statement.cpp
 * -------------------------
 * This file is the implementation for Statement
*/

#include <iostream>


#include "statement.h"

//*************Statement****************
Statement::Statement() {

}

Statement::~Statement() {

}
//**************************************

//***************RunStmt***********************
RunStmt::RunStmt() {

}

RunStmt::~RunStmt() {

}

void RunStmt::execute(Program & program, EvalState & state) {
	//从program里读出sourceLine,
	int i, len;
	std::string number;
	std::string identifier;
	std::string rest;
	int currentLineNumber = program.getFirstLineNumber();
	while (currentLineNumber >= 0) {
		std::string line = program.getSourceLine(currentLineNumber);

		number = "";//语句前的编号
		identifier = "";//语句的标识符
		rest = "";//语句的剩余部分
		//如何从rest这个字符串中分理处不同的内容。
		i = 0;
		len = line.size();
		while (line[i] == ' ' && i < len )
		{
			i++;
		}
		for (; line[i] != ' '&& i < len; i++)
		{
			number.push_back(line[i]);
		}

		while (line[i] == ' ' && i < len)
		{
			i++;
		}
		for (; line[i] != ' '&& i < len; i++)
		{
			identifier.push_back(line[i]);
		}
		while (line[i] == ' ' && i < len)
		{
			i++;
		}
		for (; i < len; i++)
		{
			if (line[i] != ' ')
				rest.push_back(line[i]);
		}

		//std::cout << "number is " << number << std::endl;
		//std::cout << "identifier is " << identifier << std::endl;
		//std::cout << "rest is " << rest << std::endl;

		if (identifier == "REM") // number REM (message) 
		{
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "LET")//number LET (var = exp)
		{
			//Expression* exp = parseExp(rest);
			std::string var;
			std::string exp;
			i = 0;
			while (rest[i] != '=')
			{
				var.push_back(rest[i++]);
			}
			i++;
			while (i < rest.size())
			{
				exp.push_back(rest[i++]);
			}
			//std::cout << "var is " << var << std::endl;
			//std::cout << "exp is " << exp << std::endl;
			state.setValue(var, parseExp(exp,state));
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "PRINT")//number PRINT (exp)
		{
			std::cout << parseExp(rest,state) << std::endl;
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "INPUT")//number INPUT (var)
		{
			int inp;
			std::cin >> inp;
			state.setValue(rest, inp);//这样不够健壮，假设了用户会按照期望输入
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "GOTO")//number GOTO (pos)
		{
			currentLineNumber = stoi(rest);//这样不够健壮，假设了用户会按照期望输入
		}
		else if (identifier == "IF")//number IF (exp ==exp THEN pos)
		{
			Expression* exp1;
			Expression* exp2;
			/*if (){
				currentLineNumber = ;
			}
			else
			{
				currentLineNumber = program.getNextLineNumber(currentLineNumber);
			}*/
		}
		else if (identifier == "END")//number END
		{
			currentLineNumber = -1;
		}
		else
		{
			//error
		}
	}
}
//*********************************************

//**************ListStmt*************
ListStmt::ListStmt() {

}

ListStmt::~ListStmt() {

}
void ListStmt::execute(Program & program,EvalState & state) {
	int lineNumber = program.getFirstLineNumber();
	while (lineNumber >= 0) {
		std::cout << program.getSourceLine(lineNumber) << std::endl;
		lineNumber = program.getNextLineNumber(lineNumber);
	}
}
//******************************************************

//********************ClearStmt*************************
ClearStmt::ClearStmt() {

}
ClearStmt::~ClearStmt() {

}

void ClearStmt::execute(Program & program,EvalState & state) {
	program.clear();
}

//*****************************************************



//*********************HelpStmt*********************
HelpStmt::HelpStmt() {

}

HelpStmt::~HelpStmt() {

}

void HelpStmt::execute(Program & program, EvalState & state) {
	//print help information
	std::cout << "Here is some Help informations" << std::endl;
}
//**************************************************



//*******************QuitStmt************************
QuitStmt::QuitStmt() {

}
QuitStmt::~QuitStmt() {

}
void QuitStmt::execute(Program & program, EvalState & state) {
	exit(0);
}
//*****************************************************



//***************PrintStmt********************************
PrintStmt::PrintStmt(TokenScanner & scanner) {  //Where is class TokenScanner from?
	//exp = readE(scanner); // and where is the method readE(scanner) from?
	//if (scanner.hasMoreTokens()) {
	//	error("Extraneous token " + scanner.nextToken());
	//}
}

PrintStmt::~PrintStmt() {
	//delete exp;
}


void PrintStmt::execute(Program & program, EvalState & state) {
	//std::cout << exp->eval(state) << std::endl;
}
//*************************************************************