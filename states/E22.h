#ifndef E22_H
#define E22_H

#include "DefaultState.h"

class E22 : public DefaultState
{
public:
	E22();
	virtual bool transitionAffectDeclare(Automaton * automaton, Symbol * affectDeclare);
	virtual bool transitionDefault(Automaton * automaton, Symbol * unknown);
};

#endif
