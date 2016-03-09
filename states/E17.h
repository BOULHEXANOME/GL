#ifndef E17_H
#define E17_H

#include "DefaultState.h"

class E17 : public DefaultState
{
    public:
        E17() : State(17) {};
		bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
