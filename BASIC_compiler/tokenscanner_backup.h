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

enum TokenType {NUMBER,OPERATOR,STRING,};

struct Tokens
{
	std::string token;
	Tokens *next;
};

class TokenScanner {
public:
	TokenScanner() :InputOperatorStream(NULL), InputTokenStream(NULL), LastOperatorPointer(NULL), LastTokenPointer(NULL){};
	TokenScanner(std::string line);
	~TokenScanner();

	/*
	 * Method: setInput
	 * Usage: setInput(string)
	 * -------------------------
	 * set the input token stream 
	*/
	void setInput(std::string line);


	/*
	 * Method: addToken
	 * Usage: scanner.addToken(token)
	 * -------------------------------------
	 * Add token into this scanner's token stream
	 *
	*/
	void addToken(std::string token);


	/*
	* Method: addOperator
	* Usage: scanner.addOperator(op)
	* -------------------------------------
	* Add operator into this scanner's operator stream
	*
	*/
	void addOperator(std::string op);


	/*
	* Method: nextToken
	* Usage: token = scanner.nextToken();
	* -------------------------------------
	* Return next token from this scanner
	* return an empty string when there are no more tokens in this scanner
	*/
	std::string nextToken();

	/*
	 * Method: hasMoreTokens
	 * Usage: if(scanner.hasMoreTokens())
	 * ---------------------------------------
	 * Return true when there are additional tokens in the scanner input token stream
	 *
	*/
	bool hasMoreTokens(TokenScanner);


	/*
	 * Method: firstToken
	 * Usage: token = scanner.firstToken();
	 * ------------------------------------
	 * Return first token from this scanner
	 * If there are no tokens, then return empty string.
	 *
	*/
	std::string getFirstToken();





	/**/
private:
	Tokens *InputTokenStream;
	Tokens *InputOperatorStream;
	Tokens *LastTokenPointer;
	Tokens *LastOperatorPointer;

	bool isOperator(std::string input);
};


#endif