#ifndef E16_H
#define E16_H

#include "DefaultState.h"

class E16 : public DefaultState
{
    public:
        E16() : State(16) {};
		bool transitionAffectDeclare(Automaton * automaton, Symbol * s);
};

#endif
