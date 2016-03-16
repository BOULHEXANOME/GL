#ifndef E39_H
#define E39_H

#include "DefaultState.h"

class E39 : public DefaultState
{
    public:
        E39() : State(39) {};
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
};

#endif
