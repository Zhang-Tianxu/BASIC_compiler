/*
* File: evalstate.cpp
* ----------------------------------
* This file is the implementation of class EvalState, which keeps track of additional information
* required by the evaluator, most notebably the values of variables
*
*/

#include <iostream>
#include <string>

#include "evalstate.h"
#include "myerror.h"

EvalState::EvalState() {

}

EvalState::~EvalState() {

}

void EvalState::setValue(std::string variable,int value) {
	std::map<std::string, int>::iterator it;
	it = variableTable.find(variable);
	if (it == variableTable.end())
		variableTable[variable] = value;
	else
	{
		variableTable.erase(variable);
		variableTable[variable] = value;
	}
}


int EvalState::getValue(std::string variable) {
	std::map<std::string, int>::iterator it;
	it = variableTable.find(variable);
	if (it != variableTable.end())
		return variableTable[variable];
	else
	{
		//throw() error
		//变量不存在
		throw  emptyVarError(variable);
	}
}


bool EvalState::isDefined(std::string variable) {
	std::map<std::string, int>::iterator it;
	it = variableTable.find(variable);
	if (it != variableTable.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}