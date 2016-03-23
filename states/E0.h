#ifndef E0_H
#define E0_H

#include "DefaultState.h"

class E0 : public DefaultState
{
public:
	E0();
	virtual bool transitionD(Automaton * automaton, Symbol * s);
	virtual bool transitionRead(Automaton * automaton, Symbol * s);
	virtual bool transitionWrite(Automaton * automaton, Symbol * s);
	virtual bool transitionId(Automaton * automaton, Symbol * s);
	virtual bool transitionConst(Automaton * automaton, Symbol * s);
	virtual bool transitionVar(Automaton * automaton, Symbol * s);
	virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};

#endif
