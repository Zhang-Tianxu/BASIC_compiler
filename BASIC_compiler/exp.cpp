/*
* File: exp.cpp
* ---------------------
* This file is the implementation for the expression module.
*
*/

#include "exp.h"

Expression::Expression() {

}
Expression::~Expression() {

}

CompoundExp::CompoundExp() {

}

CompoundExp::~CompoundExp() {

}

int CompoundExp::eval(EvalState & state) {
	return 999;
}

std::string CompoundExp::toString() {
	return "tostring";
}