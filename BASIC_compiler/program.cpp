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

}

void Program::removeSourceLine(int lineNumber) {
	//��������ڿ����׳�����Ҳ���Բ�������
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

	//�����������һ��Դ���룬�׳�����
	return program[lineNumber];
}
