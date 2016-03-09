#ifndef E20_H
#define E20_H

#include "DefaultState.h"

class E20 : public DefaultState
{
    public:
        E20() : State(20) {};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
