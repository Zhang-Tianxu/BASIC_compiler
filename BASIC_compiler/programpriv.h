/*
 * File: programpriv.h
 * -----------------------
 * contain the private parts of class Program that used to store the program
*/

#include <map>

//struct sourcelineAndStatement {
//	std::string sourceline;
//	Statement stmt;
//};
std::map<int, std::string> program;
std::map<int, Statement *> parsedProgram;

