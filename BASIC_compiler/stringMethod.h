/*
 * File: stringMethond.h
 * ----------------------
 * this file contains some method that relate with string.
 * such as split()
*/

#ifndef _stringmethod_h
#define _stringmethod_h

#include <vector>
#include <string>

/*
 * Method: split
 * Usage: slit(string,"ab",vector<string> result)
 * ----------------------------------------------------
 * split input string with "ab",and store it into the vector result.
 *
*/
void split(const std::string sourceString, const std::string splitstring, std::vector<std::string> & tokens) {
	std::string::size_type pos1, pos2;//string::size_type is a machine-independent type
	pos2 = sourceString.find(splitstring);
	pos1 = 0;
	while (pos2 != std::string::npos)//string::npos is a static member constant value with the greatest possible value for an element of type size_t.
	{
		tokens.push_back(sourceString.substr(pos1, pos2 - pos1));

		pos1 = pos2 + splitstring.size();
		pos2 = sourceString.find(splitstring, pos1);
	}
	if (pos1 != sourceString.length())
		tokens.push_back(sourceString.substr(pos1));
}


#endif