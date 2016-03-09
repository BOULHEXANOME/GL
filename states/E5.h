#ifndef E5_H
#define E5_H

#include "DefaultState.h"

class E5 : public DefaultState
{
    public:
        E5() : State(5) {};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
