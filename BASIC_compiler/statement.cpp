/*
 * File: statement.cpp
 * -------------------------
 * This file is the implementation for Statement
*/

#include <iostream>


#include "statement.h"
#include "tokenscanner.h"


Statement::Statement() {

}

Statement::~Statement() {

}

PrintStmt::PrintStmt(TokenScanner & scanner) {  //Where is class TokenScanner from?
	//exp = readE(scanner); // and where is the method readE(scanner) from?
	//if (scanner.hasMoreTokens()) {
	//	error("Extraneous token " + scanner.nextToken());
	//}
}

PrintStmt::~PrintStmt() {
	delete exp;
}

void PrintStmt::execute(EvalState & state) {
	cout << exp->eval(state) << endl;
}