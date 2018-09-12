/*
 * File: Basic.cpp
 * --------------------------
 * This file is a stub implementation of the main program
 * for the BASIC interpreter.
 */

#include <iostream>
#include <string>
#include "stringMethod.h"
#include "program.h"
#include "statement.h"
#include "myerror.h"
#include "parser.h"
#include "tokenscanner.h"



/*
 * Method: ProcessLine
 * Usage: ProcessLine(line,program,state)
 * ---------------------------------------
 * 1.When the line begins with number, store it in program by calss Program
 *
 * 2.When the line begins with token, parse it as an expression, respond it or print the result
 *
 */
void ProcessLine(std::string line, Program & program, EvalState & state) {//要保存程序和变量表
	TokenScanner scanner;
	scanner.setInput(line);
	std::string firstToken = scanner.getFirstToken();
	if (allNumber(firstToken))//Command line with number, then store it into class Program
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
	std::string line;
	std::cout << "Minimal BASIC -- Type HELP for help." << std::endl;
	while (true)
	{
		try{
			std::getline(std::cin,line);
			if (line.size() > 0)
			{
				ProcessLine(line, program, state);
			}
		}
		catch (std::exception & ex) {
			//cerr << "Error: " << ex.getMessage() << endl;
			std::cerr << "Error: " << ex.what() << std::endl;
			std::cout << "Type HELP for help information" << std::endl;
		}
		catch (char * mes)
		{
			std::cerr << "Error: " << mes << std::endl;
			std::cout << "Type HELP for help information" << std::endl;
		}
	}
	return 0;
}