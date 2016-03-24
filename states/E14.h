#ifndef E14_H
#define E14_H

#include "DefaultState.h"

class E14 : public DefaultState
{
public:
	E14();
	virtual bool transitionVal(Automaton * automaton, Symbol * s);
	virtual bool transitionF(Automaton * automaton, Symbol * s);
	virtual bool transitionT(Automaton * automaton, Symbol * s);
	virtual bool transitionE(Automaton * automaton, Symbol * s);
	virtual bool transitionId(Automaton * automaton, Symbol * s);
	virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
	virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};

#endif
