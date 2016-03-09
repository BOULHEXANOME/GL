#ifndef E21_H
#define E21_H

#include "DefaultState.h"

class E21 : public DefaultState
{
    public:
        E21() : State(21) {};
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionCloseParenthesis(Automaton * automaton, Symbol * s);
		bool transitionF(Automaton * automaton, Symbol * s);
		bool transitionT(Automaton * automaton, Symbol * s);
};

#endif
