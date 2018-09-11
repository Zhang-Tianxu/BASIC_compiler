/*
 * File: program.cpp
 * --------------------
 * This file is the implementation of the class Program
*/

#include "program.h"

Program::Program() {

}

Program::~Program() {

}

void Program::clear() {
	program.clear();
}

void Program::addSourceLine(int lineNumber, std::string line) {
	std::map<int, std::string>::iterator it;
	it = program.find(lineNumber);
	if (it == program.end()){
		program[lineNumber] = line;
	}
	else//lineNumer already exist, then replace it
	{
		program.erase(lineNumber);
		program[lineNumber] = line;
	}
	//program.insert(std::pair<int, std::string>(lineNumber, line));
	//program[lineNumber] = line;
	//std::cout << "addSourceLine end." << std::endl;

}

void Program::removeSourceLine(int lineNumber) {
	program.erase(lineNumber);
}

int Program::getFirstLineNumber() {
	//std::cout << "There is no first line" << std::endl;
	if (program.empty())
		return -1;
	else
		return (*program.begin()).first;
}

int Program::getNextLineNumber(int lineNumber) {
	std::map<int, std::string>::iterator it;
	it = program.find(lineNumber);
	if (it != program.end())
	{
		it++;
		if (it == program.end())
			return -1;
		else
			return (*it).first;

	}
	else//there is no line whose number is lineNumber
	{
		//error, the lineNumber you input is wrong.
	}
}



std::string Program::getSourceLine(int lineNumber) {
	return program[lineNumber];
}

void Program::setParsedStatement(int lineNumber, Statement *stmt) {
	std::map<int, Statement*>::iterator it;
	it = parsedProgram.find(lineNumber);
	if (it == parsedProgram.end())
	{
		parsedProgram[lineNumber] = stmt;
	}
	else
	{
		parsedProgram.erase(lineNumber);
		parsedProgram[lineNumber] = stmt;
	}
}


Statement* Program::getParsedStatement(int lineNumber) {
	std::map<int, Statement*>::iterator it;
	it = parsedProgram.find(lineNumber);
	if (it != parsedProgram.end())
	{
		return parsedProgram[lineNumber];
	}
	else
	{
		return NULL;
	}
}