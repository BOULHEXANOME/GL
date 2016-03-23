#ifndef E23_H
#define E23_H

#include "DefaultState.h"

class E23 : public DefaultState
{
public:
	E23();
	virtual bool transitionOpA(Automaton * automaton, Symbol * s);
	virtual bool transitionPlus(Automaton * automaton, Symbol * s);
	virtual bool transitionMinus(Automaton * automaton, Symbol * s);
	virtual bool transitionSemicolon(Automaton * automaton, Symbol * s);
	virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};

#endif
