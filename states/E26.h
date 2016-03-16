#ifndef E26_H
#define E26_H

#include "DefaultState.h"

class E26 : public DefaultState
{
    public:
        E26() : State(26) {};
		bool transitionVal(Automaton * automaton, Symbol * s);
};

#endif
