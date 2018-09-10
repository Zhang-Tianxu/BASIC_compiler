/*
 * File: evalstate.h
 * ----------------------------------
 * This file is the interface of class EvalState, which keeps track of additional information
 * required by the evaluator, most notebably the values of variables
*/

#ifndef _evalstate_h
#define _evalstate_h

#include <string>
#include <map>
/*
 * This class maintained a table that stored variable and their informations
*/
class EvalState {
public:
	EvalState();
	~EvalState();

	/*
	 * Method: setValue
	 * Usage: state.setValue(variable,value);
	 * --------------------
	 * Sets the value associated with the specified variable
	*/
	void setValue(std::string variable, int value);


	/*
	 * Method: getValue
	 * Usage: int value = state.getValue(variable)
	 * --------------------------------------------
	 * Get the value that associated with the specified variable
	*/

	int getValue(std::string variable);


	/*
	 * Method: isDefined
	 * Usage: if(state.isDefined(variable)){}
	 * ----------------------------------------
	 * Judge wither variable is defined
	*/
	bool isDefined(std::string variable);

private:
	std::map<std::string, int> variableTable;//<variable,value>
};
#endif