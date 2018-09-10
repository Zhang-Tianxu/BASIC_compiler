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

EvalState::EvalState() {

}

EvalState::~EvalState() {

}

void EvalState::setValue(std::string variable,int value) {
	variableTable[variable] = value;
}


int EvalState::getValue(std::string variable) {
	return variableTable[variable];
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