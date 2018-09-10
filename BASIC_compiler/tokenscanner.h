/*
* File: tokenscanner.h
* ---------------------
* This file is the interface for class TokenScanner
* which divides a string into individual tokens
*
*/

#ifndef _tokenscanner_h
#define _tokenscanner_h

#include <iostream>
#include <string>
#include <vector>

enum TokenType { NUMBER, OPERATOR, STRING, };


class TokenScanner {
public:
	TokenScanner();
	TokenScanner(std::string line);
	~TokenScanner();

	void setInput(std::string line);

	int getLength();

	std::string getFirstToken();

	std::string nextToken();
private:
	std::vector<std::string> tokens;

	//int currentPos;
};


#endif