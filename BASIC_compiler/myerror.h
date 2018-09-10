/*
 * File: myerror.h
 * ------------------------------
 * this file is the interface of calss myerror that inherit from parent class exception
 *
*/
#include <iostream>
#include <string>
#include <exception>


#ifndef _myerror_h
#define _myerror_h

class MyError: public std::exception { // How to implement my own error type?
public:
	MyError(std::string mssage);
	~MyError();

};

#endif