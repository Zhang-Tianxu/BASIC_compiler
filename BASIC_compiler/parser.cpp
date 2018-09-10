/*
* File: parser.cpp
* ----------------------
* This file is the implementation for
* the precedenec-based expression parser
*
*/


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
		;
	}
	else if (scanner.getFirstToken() == "QUIT")
	{
		return new QuitStmt();

	}
	else
	{
		;//throw error
	}
}

Expression* parseExp(TokenScanner & scanner) {
	if (scanner.getFirstToken() == "REM")
	{
		;
	}
	if (scanner.getFirstToken() == "LET")
	{
		;
	}
	if (scanner.getFirstToken() == "PRINT")
	{
		;
	}
	if (scanner.getFirstToken() == "INPUT")
	{
		;
	}
	if (scanner.getFirstToken() == "GOTO")
	{
		;
	}
	if (scanner.getFirstToken() == "IF")
	{
		;
	}
	if (scanner.getFirstToken() == "END")
	{
		;

	}
	if (scanner.getFirstToken() == "RUN")
	{
		;
	}
	if (scanner.getFirstToken() == "LIST")
	{
		;
	}
	if (scanner.getFirstToken() == "CLEAR")
	{
		;
	}
	if (scanner.getFirstToken() == "HELP")
	{
		;
	}
	if (scanner.getFirstToken() == "QUIT")
	{

	}
	return NULL;
}