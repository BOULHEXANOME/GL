#ifndef E26_H
#define E26_H

#include "DefaultState.h"

class E26 : public DefaultState
{
public:
	E26();
	virtual bool transitionVal(Automaton * automaton, Symbol * val);
};

#endif
