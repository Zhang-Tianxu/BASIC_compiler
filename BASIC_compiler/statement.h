/*
 * File: statement.h
 * ------------------------------
 * This file is a interfae for Statement class
 * Statement itself is a virtual class(abstract class) which defines
 * the structure and behavior of a set of classes but has no
 * objects of its own.  Any object must be one of the concrete subclasses of Expression:
 *
 *                                Statement
 *                        /   /   /   |   \   \   \
 *                       /   /   /    |    \   \   \
 *                      /   /   /     |     \   \   \
 *                     /   /   /      |      \   \   \
 *                 Rem  Let  Print  Input   Goto  If  End
*/

#ifndef _statement_h
#define _statement_h


#include "exp.h"
#include "evalstate.h"
#include "tokenscanner.h"
#include "program.h"

class Program;//类的前置声明，缺少会出现error C2061
class Statement {
public:
	Statement();
	virtual ~Statement();
	virtual void execute(Program & program,EvalState & state) = 0;//pure virtual method
	//virtual void execute(Program & program) = 0;
//private:
};


//********************************************
class ListStmt :public Statement {
public:
	ListStmt();
	virtual ~ListStmt();
	virtual void execute(Program & program, EvalState & state);
};

//*********************************************
class ClearStmt :public Statement {
public:
	ClearStmt();
	virtual ~ClearStmt();

	virtual void execute(Program & program, EvalState & state);
};
//*********************************************
class HelpStmt :public Statement {
public:
	HelpStmt();
	virtual ~HelpStmt();

	virtual void execute(Program & program, EvalState & state);

};
//*********************************************
class QuitStmt :public Statement {
public:
	QuitStmt();
	virtual ~QuitStmt();

	virtual void execute(Program & program, EvalState & state);
};

class PrintStmt :public Statement {
public:
	PrintStmt(TokenScanner & scanner);
	virtual ~PrintStmt();

	/*
	 * Method: execute
	 * Usage: 
	 * -----------------------------------------------------------
	 * An execute method, which allows the interpreter to simulate the operation 
	 * of that statement when the program runs. 
	 * For the LetStmt class, the execute method has to evaluate the expression 
	 * that appeared on the right side of the equal sign and then store 
	 * that value in the variable that appears on the left side.
	 *
	*/
	virtual void execute(Program & program, EvalState & state);
private:
	Expression *exp;
};

class RemStmt :public Statement {

};

class LetStmt :public Statement {

};

class InputStmt :public Statement {

};

class GotoStmt :public Statement {

};

class IfStmt :public Statement {

};

class EndStmt :public Statement {

};



#endif