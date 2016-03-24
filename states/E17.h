#ifndef E17_H
#define E17_H

#include "DefaultState.h"

class E17 : public DefaultState
{
public:
	E17();
	virtual bool transitionId(Automaton * automaton, Symbol * s);
	virtual bool transitionDefault(Automaton * automaton, Symbol* unknown);
};

#endif
