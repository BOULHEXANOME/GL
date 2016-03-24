#ifndef E11_H
#define E11_H

#include "DefaultState.h"

class E11 : public DefaultState
{
public:
	E11();
	virtual bool transitionAffectInstruct(Automaton * automaton, Symbol * s);
	virtual bool transitionDefault(Automaton *automaton, Symbol *unknown);
};

#endif
