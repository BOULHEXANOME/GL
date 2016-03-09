#ifndef E7_H
#define E7_H

#include "DefaultState.h"

class E7 : public DefaultState
{
    public:
        E7() : State(7) {};
		bool transitionAff(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
