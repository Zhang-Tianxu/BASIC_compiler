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


class Statement;

enum IdentifierType {REM,LET,PRINT,INPUT,GOTO,IF,END,RUN,LIST,CLEAR,HELP,QUIT};

enum VType {VARIABLE,DIGIT,UNKNOW};

class VarOrDigit {
public:
	VarOrDigit() :type(UNKNOW){};
	~VarOrDigit(){};
	void setType(VType t)
	{
		type = t;
	}
	VType getType() {
		return type;
	}
	void setContent(std::string con) {
		content = con;
	}
	void addContentC(char c) {
		if (isdigit(c) && type == UNKNOW)
		{
			content.push_back(c);
			type = DIGIT;
		}
		else if (isdigit(c))
		{
			content.push_back(c);
		}
		else if (type == UNKNOW)
		{
			content.push_back(c);
			type = VARIABLE;
		}
		else if (type == VARIABLE)
		{
			content.push_back(c);
		}
		else
		{
			//error
			std::cout << "Variables can't start with digit" << std::endl;
		}
	}
	std::string getContent() {
		return content;
	}
	void clear(){
		type = UNKNOW;
		content.clear();
	}
private:
	VType type;
	std::string content;
};

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




/*
 * 
*/


/*
 * Method: isOperator
 * Usage: bool = isOperator(char)
 * -------------------------------------
 * return true if input char is operator
 *
*/
bool isOperator(char c);


/*
 * Method: getIndex
 * Usage: int index = getIndex(operator)
 * -------------------------------------
 * Return the index of the operator
 * the index is definde by the priority table
 *  -----------------------------------------------
 *       |  +  |  -  |  *  |  /  |  (  |  )  |  #  |  
 *  -----------------------------------------------
 *    +  |  >  |  >  |  <  |  <  |  <  |  >  |  >  |
 *  -----------------------------------------------
 *    -  |  >  |  >  |  <  |  <  |  <  |  >  |  >  |
 *  -----------------------------------------------
 *    *  |  >  |  >  |  >  |  >  |  <  |  >  |  >  |
 *  -----------------------------------------------
 *    /  |  >  |  >  |  >  |  >  |  <  |  >  |  >  |
 *  -----------------------------------------------
 *    (  |  <  |  <  |  <  |  <  |  <  |  =  |     |
 *  -----------------------------------------------
 *    )  |  >  |  >  |  >  |  >  |     |  >  |  >  |
 *  -----------------------------------------------
 *    #  |  <  |  <  |  <  |  <  |  <  |     |  =  |
 *  -----------------------------------------------
*/

int getIndex(char opt);

/*
 * Method:getPriority
 * Usage: char ans = getPriority('+','*')
 * ------------------------------------------
 * Compare priority between two operators, if opt1 prior to opt2
 * then return '>',else return '<'
*/
char getPriority(char opt1, char opt2);

/*

*/
int calculate(int b, char opt, int a);   //¼ÆËãb opt a


/*
 * Method: parseExp
 * Usage: parseExp(line,state)
 * ----------------------------
 * 
*/
int parseExp(std::string line,EvalState & state);

//Expression* readE(TokenScanner & scanner, int prec = 0);
//
//Expression* readT(TokenScanner & scanner);
//
//int precedence(std::string operatorToken);

#endif