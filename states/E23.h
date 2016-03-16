#ifndef E23_H
#define E23_H

#include "DefaultState.h"

class E23 : public DefaultState
{
    public:
        E23() : State(23) {};
		bool transitionOpA(Automaton * automaton, Symbol * s);
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif