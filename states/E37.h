#ifndef E37_H
#define E37_H

#include "DefaultState.h"

class E37 : public DefaultState
{
    public:
        E37() : State(37) {};
		bool transitionOpA(Automaton * automaton, Symbol * s);
		bool transitionClosingParenthesis(Automaton * automaton, Symbol * s);
		bool transitionPlus(Automaton * automaton, Symbol * s);
		bool transitionMinus(Automaton * automaton, Symbol * s);
};

#endif
