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


class TokenScanner {
public:
	TokenScanner();
	TokenScanner(std::string line);
	~TokenScanner();

	std::vector<std::string> getTokens();
	void setInput(std::string line);

	int getLength();

	std::string getFirstToken();

	std::string getSecondToken();
private:
	std::vector<std::string> tokens;
};


#endif