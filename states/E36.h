#ifndef E36_H
#define E36_H

#include "DefaultState.h"

class E36 : public DefaultState
{
    public:
        E36() : State(36) {};
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
		bool transitionT(Automaton * automaton, Symbol * s);
		bool transitionE(Automaton * automaton, Symbol * s);
		bool transitionF(Automaton * automaton, Symbol * s);
};

#endif
