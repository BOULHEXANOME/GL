#ifndef E40_H
#define E40_H

#include "DefaultState.h"

class E40 : public DefaultState
{
    public:
        E40() : State(40) {};
		bool transitionRead(Automaton * automaton, Symbol * s);
		bool transitionWrite(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionVar(Automaton * automaton, Symbol * s);
		bool transitionConst(Automaton * automaton, Symbol * s);
};

#endif
