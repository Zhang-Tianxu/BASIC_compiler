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


TokenScanner::TokenScanner() {

}

TokenScanner::TokenScanner(std::string line) {
	split(line, " ", tokens);
}

TokenScanner::~TokenScanner() {

}

void TokenScanner::setInput(std::string line) {
	split(line, " ", tokens);
}


int TokenScanner::getLength() {
	return tokens.size();
}

std::string TokenScanner::getFirstToken() {
	return tokens[0];
}


std::string TokenScanner::nextToken() {
	return tokens[1];
}
