#ifndef E22_H
#define E22_H

#include "DefaultState.h"

class E22 : public DefaultState
{
    public:
        E22() : State(22) {};
		bool transitionAffectDeclare(Automaton * automaton, Symbol * s);
};

#endif
