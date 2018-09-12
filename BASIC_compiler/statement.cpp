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
	int i, len;
	std::string number;
	std::string identifier;
	std::string rest;

	int currentLineNumber = program.getFirstLineNumber();

	while (currentLineNumber >= 0) {
		std::string line = program.getSourceLine(currentLineNumber);
		len = line.size();
		number = "";
		identifier = "";
		rest = "";


		i = 0;
		while (line[i] == ' ' && i < len)
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


		if (identifier == "REM") // number REM (message) 
		{
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "LET")//number LET (var = exp)
		{
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

			if (isdigit(var[0]))
			{
				//变量不能以数字开头，抛出错误
				throw "variable can't start with number!";
			}
			state.setValue(var, parseExp(exp, state));
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "PRINT")//number PRINT (exp)
		{
			std::cout << parseExp(rest, state) << std::endl;
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "INPUT")//number INPUT (var)
		{
			int inp;
			std::cin >> inp;
			state.setValue(rest, inp);
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "GOTO")//number GOTO (pos)
		{
			currentLineNumber = stoi(rest);//这样不够健壮，假设了用户会按照期望输入
		}
		else if (identifier == "IF")//number IF (exp ==exp THEN pos)
		{
			std::string exp1;
			char comparisonSign;
			std::string exp2;
			std::string pos;


			i = 0;
			while (rest[i] != '>' && rest[i] != '<'&&rest[i] != '=')
				exp1.push_back(rest[i++]);
			comparisonSign = rest[i++];
			while (i < rest.find("THEN"))
			{
				exp2.push_back(rest[i++]);
			}
			i += 4;
			while (i < rest.size())
			{
				pos.push_back(rest[i++]);
			}

			if (comparisonSign == '=' && parseExp(exp1, state) == parseExp(exp2, state))
				currentLineNumber = stoi(pos);
			if (comparisonSign == '<' && parseExp(exp1, state) < parseExp(exp2, state))
				currentLineNumber = stoi(pos);
			if (comparisonSign == '>' && parseExp(exp1, state) > parseExp(exp2, state))
				currentLineNumber = stoi(pos);
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "END")//number END
		{
			currentLineNumber = -1;
		}
		else
		{
			//error
			throw "wrong Statement!";
		}
	}
}
//*********************************************

//**************ListStmt*************
ListStmt::ListStmt() {

}

ListStmt::~ListStmt() {

}
void ListStmt::execute(Program & program, EvalState & state) {
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

void ClearStmt::execute(Program & program, EvalState & state) {
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
	std::cout <<
		"COMMAND:" << std::endl
		<< "1:RUN" << std::endl
		<< "******************" << std::endl
		<< "    run the program you stored" << std::endl
		<< std::endl
		<< "2:LIST" << std::endl
		<< "******************" << std::endl
		<< "    print the program you stored" << std::endl
		<< std::endl
		<< "3:CLEAR" << std::endl
		<< "******************" << std::endl
		<< "    clear the program you stored" << std::endl
		<< std::endl
		<< "4:HELP" << std::endl
		<< "******************" << std::endl
		<< "    ask for help information" << std::endl
		<< std::endl
		<< "5:QUIT" << std::endl
		<< "******************" << std::endl
		<< "    exit" << std::endl
		<< std::endl
		<< "6:PRINT" << std::endl
		<< "******************" << std::endl
		<< "    PRINT exp .print the expression." << std::endl
		<< std::endl
		<< "7:LET" << std::endl
		<< "******************" << std::endl
		<< "    LET var = exp. Assign exp's result to var. " << std::endl
		<< std::endl
		<< "8:INPUT" << std::endl
		<< "******************" << std::endl
		<< "    INPUT var. Input a value and assign it to var." << std::endl
		<< std::endl
		<< "PROGRAM:" << std::endl
		<< "******************" << std::endl
		<< "program sentence must start with number and one of the statement that follows:" << std::endl
		<< std::endl
		<< "1:REM" << std::endl
		<< "******************" << std::endl
		<< "	Followed by comments" << std::endl
		<<  std::endl
		<< "2:LET" << std::endl
		<< "******************" << std::endl
		<< "	LET var = exp. Assign exp's result to var." << std::endl
		<<  std::endl
		<< "3:PRINT" << std::endl
		<< "******************" << std::endl
		<< "	PRINT exp .print the expression." << std::endl
		<<  std::endl
		<< "4:INPUT" << std::endl
		<< "******************" << std::endl
		<< "	INPUT var. Input a value and assign it to var." << std::endl
		<<  std::endl
		<< "5:GOTO" << std::endl
		<< "******************" << std::endl
		<< "	GOTO n. Forces an unconditional change in the control flow of the program." << std::endl
		<<  std::endl
		<< "6:IF/THEN" << std::endl
		<< "******************" << std::endl
		<< "	IF exp1 op exp2 THEN n. where exp1 and exp2 are expressions and op is one of the conditional operators = , <, or >.If the condition holds, the program should continue from line n just as in the GOTO statement.If not, the program continues on to the next line" << std::endl
		<<  std::endl
		<< "7:END" << std::endl
		<< "******************" << std::endl
		<< "	Marks the end of the program." << std::endl;
}
//**************************************************



//*******************QuitStmt************************
QuitStmt::QuitStmt() {

}
QuitStmt::~QuitStmt() {

}
void QuitStmt::execute(Program & program, EvalState & state) {
	std::cout << "Bye!" << std::endl;
	exit(0);
}
//*****************************************************



//***************PrintStmt********************************
PrintStmt::PrintStmt(TokenScanner & scanner) {
	int i = 1;
	while (i < scanner.getTokens().size())
	{
		line += scanner.getTokens()[i++];
	}
}

PrintStmt::~PrintStmt() {

}


void PrintStmt::execute(Program & program, EvalState & state) {
	std::cout << parseExp(line, state) << std::endl;
}
//*************************************************************

//***************LetStmt********************************
LetStmt::LetStmt(TokenScanner & scanner) {
	int i = 1;
	while (i < scanner.getTokens().size())
	{
		line += scanner.getTokens()[i++];
	}
}

LetStmt::~LetStmt() {

}


void LetStmt::execute(Program & program, EvalState & state) {
	std::string var;
	std::string exp;
	int i = 0;
	while (line[i] != '=')
	{
		var.push_back(line[i++]);
	}
	i++;
	while (i < line.size())
	{
		exp.push_back(line[i++]);
	}

	if (isdigit(var[0]))
	{
		//变量不能以数字开头，抛出错误
		throw "variable can't start with number!";
	}
	state.setValue(var, parseExp(exp, state));
}
//*************************************************************

//***************InputStmt********************************
InputStmt::InputStmt(TokenScanner & scanner) {
	int i = 1;
	while (i < scanner.getTokens().size())
	{
		line += scanner.getTokens()[i++];
	}
}

InputStmt::~InputStmt() {

}


void InputStmt::execute(Program & program, EvalState & state) {
	int inp;
	std::cin >> inp;
	state.setValue(line, inp);
}
//*************************************************************