/*
* File: tokenscanner.cpp
* ---------------------
* This file is the implementation for class TokenScanner
* which divides a string into individual tokens
*
*/

#include <iostream>
#include <string>
#include <vector>

#include "tokenscanner.h"
#include "stringMethod.h"
#include "evalstate.h"


/*
 * Construct method
*/

TokenScanner::TokenScanner(std::string line):InputTokenStream(NULL), InputOperatorStream(NULL),LastOperatorPointer(NULL),LastTokenPointer(NULL) {
	std::vector<std::string> tokens;
	split(line, " ", tokens);
	for (auto it = tokens.begin(); it != tokens.end(); it++)
	{
		if (isOperator(*it))
			addOperator(*it);
		else
			addToken(*it);
	}
}

TokenScanner::~TokenScanner() {

}
/*
 * Method: setInput
 * Usage: scanner.setInput(string line)
 * ---------------------------------
 * devide line into tokens and store in class TokenScanner
 * 
*/
void TokenScanner::setInput(std::string line) {//还要保存evalstate里面的variableTable表
	std::vector<std::string> tokens;
	split(line, " ", tokens);
	for (auto it = tokens.begin(); it != tokens.end(); it++)
	{
		if (isOperator(*it))
			addOperator(*it);
		else
			addToken(*it);
	}
}

void TokenScanner::addToken(std::string token) {
	Tokens *tmp = new Tokens;
	tmp->next = NULL;
	tmp->token = token;
	if (InputTokenStream == NULL)
	{
		InputTokenStream = tmp;
		LastTokenPointer = InputTokenStream;
	}
	else
	{
		LastTokenPointer->next = tmp;
		LastTokenPointer = LastTokenPointer->next;
	}
	
}

void TokenScanner::addOperator(std::string op) {
	Tokens *tmp = new Tokens;
	tmp->next = NULL;
	tmp->token = op;
	if (InputOperatorStream == NULL)
	{
		InputOperatorStream = tmp;
		LastOperatorPointer = tmp;
	}
	else
	{
		LastOperatorPointer->next = tmp;
		LastOperatorPointer = LastOperatorPointer->next;
	}
}

bool TokenScanner::isOperator(std::string input) {
	if (input == "+" || input == "-" || input == "*" || input == "/" || input == "=")
		return true;
	else
		return false;
}

std::string TokenScanner::getFirstToken() {
	return InputTokenStream->token;
}

