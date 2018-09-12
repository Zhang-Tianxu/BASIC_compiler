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

class emptyVarError:public std::exception {
public:
	emptyVarError();
	emptyVarError(std::string var);
	~emptyVarError();
	const std::string what()
	{
		return message;
	}
private:
	std::string message;
};

class wrongInput :public std::exception {
public:
	wrongInput();
	~wrongInput();
	const std::string what()
	{
		return message;
	}
private:
	std::string message;
};


class wrongExpressionFormat :public std::exception {
public:
	wrongExpressionFormat();
	wrongExpressionFormat(std::string exp);
	~wrongExpressionFormat();
	const std::string what()
	{
		return message;
	}
private:
	std::string message;
};
#endif