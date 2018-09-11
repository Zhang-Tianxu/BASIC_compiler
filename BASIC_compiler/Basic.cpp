/*
 * File: Basic.cpp
 * --------------------------
 * This file is a stub implementation of the main program
 * for the BASIC interpreter.
 */

#include <iostream>
#include <string>

#include "program.h"
#include "statement.h"
#include "myerror.h"
#include "parser.h"
#include "tokenscanner.h"


using namespace std;

/*
 * Method: ProcessLine
 * Usage: ProcessLine(line,program,state)
 * ---------------------------------------
 * 1.When the line begins with number, store it in program by calss Program
 *
 * 2.When the line begins with token, parse it as an expression, respond it or print the result
 *
 */
void ProcessLine(string line, Program & program, EvalState & state) {//要保存程序和变量表
	TokenScanner scanner;
	scanner.setInput(line);
	std::string firstToken = scanner.getFirstToken();
	if (isdigit(firstToken[0]))//Command line with number, then store it into class Program
	{
		int tokenNumber = stoi(firstToken);
		if (scanner.getLength() > 1)
		{
			program.addSourceLine(tokenNumber, line);
		}
		else//only line number, then delete sourceline
		{
			program.removeSourceLine(tokenNumber);
		}
	}
	else//Command line with no number, then excute it directly
	{
		Statement* statement = parseStatement(scanner);
		statement->execute(program,state);
	}
	
}

int main()
{
	EvalState state;
	Program program;
	string line;
	cout << "Minimal BASIC -- Type HELP for help." << endl;
	while (true)
	{
		try{
			getline(cin,line);
			ProcessLine(line, program, state);
			//int lineNumber = program.getFirstLineNumber();
			//while (lineNumber >= 0) {
			//	cout << program.getSourceLine(lineNumber) << endl;
			//	lineNumber = program.getNextLineNumber(lineNumber);
			//}
		}
		catch (MyError & ex) {
			//cerr << "Error: " << ex.getMessage() << endl;
		}
	}
	return 0;
}