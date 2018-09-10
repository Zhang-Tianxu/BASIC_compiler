/*
 * File: parser.h
 * ----------------------
 * This file is the interface for 
 * the precedenec-based expression parser
 *
*/

#ifndef _parser_h
#define _parser_h

#include <string>

#include "exp.h"
#include "statement.h"
#include "tokenscanner.h"
#include "program.h"




enum IdentifierType {REM,LET,PRINT,INPUT,GOTO,IF,END,RUN,LIST,CLEAR,HELP,QUIT};

/*
 * Method: parseExp
 * Usage: Expression* expression = parseExp(scanner)
 * --------------------------------------------------
 * This method parse input tokens, and return an Expression pointer
 *
*/

/*
 * The strategy for parsing a statement in BASIC begins by reading the first token on the line. 
 * If that token is the name of one of the seven legal statement forms,
 * all you have to do is call the constructor for the appropriate Statement subclass. 
 * For example, if the first token you read from the scanner is PRINT, 
 * you can create the appropriate PrintStmt statement form by calling "new PrintStmt(scanner)"
 * which will then go through and read the remaining tokens on the line and assemble them into a PrintStmt object.
 *
*/
Statement* parseStatement(TokenScanner & scanner);

Expression* parseExp(TokenScanner & scanner);

Expression* readE(TokenScanner & scanner, int prec = 0);

Expression* readT(TokenScanner & scanner);

int precedence(std::string operatorToken);

#endif