/*
 * File: exp.h
 * ---------------------
 * This file is the interface for the expression（表达式） module.
 * Expression itself is virtural class (abstract class),it must be implete a one of ConstantExp,IdentifierExp, or CompoundExp
 *
 *                             Expression
 *                        /         |        \
 *                       /          |         \
 *              ConstantExp   IdentifierExp   CompoundExp
 *
*/

#ifndef _exp_h
#define _exp_h

#include "evalstate.h"


enum ExpressionType {CONSTANT,IDENTIFIER,COMPOUND};//常量表达式，标识符/关键字表达式，复合表达式


class Expression {
public:
	Expression();
	virtual ~Expression();


	/*
	 * Methond: eval
	 * Usage: int value = exp->eval(state)
	 * ----------------------------------------
	 * Evaluates this expression and return its value in the context of the specified EvalState object
	 *
	*/
	virtual int eval(EvalState & state) = 0;//This is a PVF(Pure Virtual Function)

	/*
	 * Method: toString
	 * Usage: string str = exp->toString();
	 * --------------------------------------
	 * Returns a string representation of this expression
	*/
	virtual std::string toString() = 0;//This is a PVF(Pure Virtual Function)

	/*
	 * Method: getType
	 * Usage: ExpressionType type = exp->getType();
	 * ---------------------------------------------
	 * Returns the type of the expression, which must be one of the constants
	 * CONSTANT, IDENTIFIER, or COMPOUND.
	*/
	//virtual ExpressionType getType() = 0;//This is a PVF(Pure Virtual Function)
private:
};


//inherite and add their own method
//class ConstantExp:public Expression {
//
//};
//
//class IdentifierExp :public Expression {
//
//};

class CompoundExp :public Expression {
public:
	CompoundExp();
	virtual ~CompoundExp();
	virtual int eval(EvalState & state);
	virtual std::string toString();
};

#endif