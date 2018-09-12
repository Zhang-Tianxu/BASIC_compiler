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
void split(const std::string sourceString, const std::string splitstring, std::vector<std::string> & tokens);


bool allNumber(std::string s);

#endif