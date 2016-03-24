#ifndef DEFAULTSTATE_H
#define DEFAULTSTATE_H

#include <string>
#include "../Automaton.h"
#include "../Symbols/Symbol.h"
class Symbol;

class DefaultState
{
private:
	bool alreadyOneError;

protected:
	std::string expectedSymbols = "None.";

public:
	int state;
	DefaultState();
	~DefaultState();

	virtual bool transition(Automaton * automaton, Symbol * s);
	virtual bool transitionPlus(Automaton * automaton, Symbol * s);
	virtual bool transitionMinus(Automaton * automaton, Symbol * s);
	virtual bool transitionMultiply(Automaton * automaton, Symbol * s);
	virtual bool transitionDivide(Automaton * automaton, Symbol * s);
	virtual bool transitionWrite(Automaton * automaton, Symbol * s);
	virtual bool transitionRead(Automaton * automaton, Symbol * s);
	virtual bool transitionAffectDeclare(Automaton * automaton, Symbol * s);
	virtual bool transitionAffectInstruct(Automaton * automaton, Symbol * s);
	virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
	virtual bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
	virtual bool transitionVar(Automaton * automaton, Symbol * s);
	virtual bool transitionVal(Automaton * automaton, Symbol * s);
	virtual bool transitionDollar(Automaton * automaton, Symbol * s);
	virtual bool transitionConst(Automaton * automaton, Symbol * s);
	virtual bool transitionComma(Automaton * automaton, Symbol * s);
	virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
	virtual bool transitionId(Automaton * automaton, Symbol * s);

	virtual bool transitionError(Automaton * automaton, Symbol * s);
	virtual bool transitionDefault(Automaton * automaton, Symbol * s);

	virtual bool transitionP(Automaton * automaton, Symbol * s);
	virtual bool transitionD(Automaton * automaton, Symbol * s);
	virtual bool transitionD_Prime(Automaton * automaton, Symbol * s);
	virtual bool transitionIdList(Automaton * automaton, Symbol * s);
	virtual bool transitionAff(Automaton * automaton, Symbol * s);
	virtual bool transitionI(Automaton * automaton, Symbol * s);
	virtual bool transitionI_Prime(Automaton * automaton, Symbol * s);
	virtual bool transitionE(Automaton * automaton, Symbol * s);
	virtual bool transitionT(Automaton * automaton, Symbol * s);
	virtual bool transitionF(Automaton * automaton, Symbol * s);
	virtual bool transitionOpA(Automaton * automaton, Symbol * s);
	virtual bool transitionOpM(Automaton * automaton, Symbol * s);

	/***********************/
	/*** Getters/Setters ***/
	/***********************/
	std::string getExpectedSymbols() const
	{
		return expectedSymbols;
	}
	/************************/
	/** End Getters/Setters */
	/************************/

};

#endif
