#ifndef E38_H
#define E38_H

#include "DefaultState.h"

class E38 : public DefaultState
{
    public:
        E38() : State(38) {};
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionVal(Automaton * automaton, Symbol * s);
		bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s);
};

#endif
