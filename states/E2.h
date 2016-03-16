#ifndef E2_H
#define E2_H

#include "DefaultState.h"

class E2 : public DefaultState
{
    public:
        E1() : E1() {this->state = 1;};
		bool transitionId_Liste(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
