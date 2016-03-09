#ifndef E6_H
#define E6_H

#include "DefaultState.h"

class E6 : public DefaultState
{
    public:
        E6() : State(6) {};
		bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
