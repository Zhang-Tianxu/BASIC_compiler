/*
* File: parser.cpp
* ----------------------
* This file is the implementation for
* the precedenec-based expression parser
*
*/


#include "parser.h"
#include "exp.h"

Expression* parseExp(TokenScanner & scanner) {
	if (scanner.getFirstToken() == "REM")
	{

	}
	if (scanner.getFirstToken() == "LET")
	{

	}
	if (scanner.getFirstToken() == "PRINT")
	{

	}
	if (scanner.getFirstToken() == "INPUT")
	{

	}
	if (scanner.getFirstToken() == "GOTO")
	{

	}
	if (scanner.getFirstToken() == "IF")
	{

	}
	if (scanner.getFirstToken() == "END")
	{

	}
	if (scanner.getFirstToken() == "RUN")
	{

	}
	if (scanner.getFirstToken() == "LIST")
	{

	}
	if (scanner.getFirstToken() == "CLEAR")
	{

	}
	if (scanner.getFirstToken() == "HELP")
	{

	}
	if (scanner.getFirstToken() == "QUIT")
	{

	}
	return NULL;
}