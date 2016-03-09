#ifndef E12_H
#define E12_H

#include "DefaultState.h"

class E12 : public DefaultState
{
    public:
        E12() : State(12) {};
		bool transitionComma(Automaton * automaton, Symbol * s);
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
