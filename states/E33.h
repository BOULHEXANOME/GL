#ifndef E33_H
#define E33_H

#include "DefaultState.h"

class E33 : public DefaultState
{
    public:
        E33() : State(33) {};
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
};

#endif
