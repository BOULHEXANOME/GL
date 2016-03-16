#ifndef E32_H
#define E32_H

#include "DefaultState.h"

class E32 : public DefaultState
{
    public:
        E32() : State(32) {};
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
};

#endif
