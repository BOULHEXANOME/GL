#ifndef E25_H
#define E25_H

#include "DefaultState.h"

class E25 : public DefaultState
{
    public:
        E25() : State(25) {};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
