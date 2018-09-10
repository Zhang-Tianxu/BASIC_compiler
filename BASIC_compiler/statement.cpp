/*
 * File: statement.cpp
 * -------------------------
 * This file is the implementation for Statement
*/

#include <iostream>


#include "statement.h"


Statement::Statement() {

}

Statement::~Statement() {

}


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
//********************ClearStmt***********************************
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