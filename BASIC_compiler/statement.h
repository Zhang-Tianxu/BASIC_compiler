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


//#include "exp.h"
#include "evalstate.h"
#include "tokenscanner.h"
#include "program.h"
#include "parser.h"

class Program;//类的前置声明，缺少会出现error C2061

/*
 * Virtual Class: Statement
 * --------------------------
 * Class Statement is a superclass
 *
*/
class Statement {
public:
	Statement();
	virtual ~Statement();
	virtual void execute(Program & program,EvalState & state) = 0;//pure virtual method
	//virtual void execute(Program & program) = 0;
//private:
};

/*
 * Subclass: RunStmt
 * --------------------------
 * Statement of run
*/
class RunStmt :public Statement {
public:
	RunStmt();
	virtual ~RunStmt();
	virtual void execute(Program & program, EvalState & state);
};

/*
 * Subclass: ListStmt
 * --------------------------
 * Statement of list
 *
*/
class ListStmt :public Statement {
public:
	ListStmt();
	virtual ~ListStmt();
	virtual void execute(Program & program, EvalState & state);
};

/*
 * Subclass: ClearStmt
 * ----------------------
 * Statement of clear
 *
*/
class ClearStmt :public Statement {
public:
	ClearStmt();
	virtual ~ClearStmt();

	virtual void execute(Program & program, EvalState & state);
};
/*
 * Subclass: HelpStmt
 * --------------------------
 * Statement of help
 * 
*/
class HelpStmt :public Statement {
public:
	HelpStmt();
	virtual ~HelpStmt();

	virtual void execute(Program & program, EvalState & state);

};


/*
 * Subclass: QuitStmt
 * ------------------------
 * Statement of quit
*/
class QuitStmt :public Statement {
public:
	QuitStmt();
	virtual ~QuitStmt();

	virtual void execute(Program & program, EvalState & state);
};


/*
 * Subclass: PrintStmt
 * ---------------------------
 * Statement of Print
*/
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
//private:
//	Expression *exp;
};

#endif