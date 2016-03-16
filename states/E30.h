#ifndef E30_H
#define E30_H

#include "DefaultState.h"

class E30 : public DefaultState
{
    public:
        E30() : State(30) {};
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
		bool transitionF(Automaton * automaton, Symbol * s);
};

#endif
