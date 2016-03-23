#ifndef E32_H
#define E32_H

#include "DefaultState.h"

class E32 : public DefaultState
{
public:
	E32();
	virtual bool transitionId(Automaton * automaton, Symbol * s);
	virtual bool transitionVal(Automaton * automaton, Symbol * s);
	virtual bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
};

#endif
