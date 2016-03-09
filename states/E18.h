#ifndef E18_H
#define E18_H

#include "DefaultState.h"

class E18 : public DefaultState
{
    public:
        E18() : State(18) {};
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
		bool transitionOpA(Automaton * automaton, Symbol * s);
};

#endif
