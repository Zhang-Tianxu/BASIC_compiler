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
	int currentLineNumber = program.getFirstLineNumber();
	while (currentLineNumber >= 0) {
		//std::vector<std::string> tokens;
		//split(program.getSourceLine(currentLineNumber), " ", tokens);
		std::string number;//语句前的编号
		std::string identifier;//语句的标识符
		std::string rest;//语句的剩余部分

		if (identifier == "REM")
		{
			
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
			std::cout << "REM normal" << std::endl;
		}
		else if (identifier == "LET")
		{
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "PRINT")
		{
			/*Expression* exp = parseExp();
			std::cout << exp->eval << std::endl;*/
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
		}
		else if (identifier == "INPUT")
		{
			int inp;
			std::cin >> inp;
			state.setValue(rest, inp);//这样不够健壮，假设了用户会按照期望输入
			currentLineNumber = program.getNextLineNumber(currentLineNumber);
			std::cout << "INPUT normal" << std::endl;
		}
		else if (identifier == "GOTO")
		{
			currentLineNumber = stoi(rest);//这样不够健壮，假设了用户会按照期望输入
		}
		else if (identifier == "IF")
		{
			/*if (){
				currentLineNumber = ;
			}
			else
			{
				currentLineNumber = program.getNextLineNumber(currentLineNumber);
			}*/
		}
		else if (identifier == "END")
		{
			currentLineNumber = -1;
			std::cout << "END normal" << std::endl;
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
	delete exp;
}


void PrintStmt::execute(Program & program, EvalState & state) {
	std::cout << exp->eval(state) << std::endl;
}
//*************************************************************