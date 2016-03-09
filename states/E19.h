#ifndef E19_H
#define E19_H

#include "DefaultState.h"

class E19 : public DefaultState
{
    public:
        E19() : State(19) {};
		bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
