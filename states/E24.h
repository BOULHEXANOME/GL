#ifndef E24_H
#define E24_H

#include "DefaultState.h"

class E24 : public DefaultState
{
    public:
        E24() : State(24) {};
		bool transitionVar(Automaton * automaton, Symbol * s);
};

#endif
