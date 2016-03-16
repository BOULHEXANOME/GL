#ifndef E28_H
#define E28_H

#include "DefaultState.h"

class E28 : public DefaultState
{
    public:
        E28() : State(28) {};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
