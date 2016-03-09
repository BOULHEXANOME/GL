#ifndef E9_H
#define E9_H

#include "DefaultState.h"

class E9 : public DefaultState
{
    public:
        E9() : State(9) {};
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionF(Automaton * automaton, Symbol * s);
		bool transitionT(Automaton * automaton, Symbol * s);
		bool transitionOpenParenthesis(Automaton * automaton, Symbol * s);
		bool transitionE(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
};

#endif
