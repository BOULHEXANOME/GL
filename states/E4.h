#ifndef E4_H
#define E4_H

#include "DefaultState.h"

class E4 : public DefaultState
{
    public:
        E4() : State(4) {};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
