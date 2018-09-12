/*
* File: myerror.cpp
* ------------------------------
* this file is the implementation of calss myerror that inherit from parent class exception
*
*/

#include <iostream>
#include <string>

#include "myerror.h"

emptyVarError::emptyVarError() {

}
emptyVarError::emptyVarError(std::string var)
{
	message = var + "is not defined!";
}
emptyVarError::~emptyVarError() {

}



wrongInput::wrongInput() {
	message = "Input wrong!";
}
wrongInput::~wrongInput() {

}

wrongExpressionFormat::wrongExpressionFormat() {
	message = "It is not a correct expression!";
}

wrongExpressionFormat::wrongExpressionFormat(std::string exp) {
	message = exp + " is not a correct expression!";
}

wrongExpressionFormat::~wrongExpressionFormat() {

}