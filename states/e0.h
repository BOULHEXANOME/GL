#ifndef E0_H
#define E0_H

#include "DefaultState.h"

class E0 : public DefaultState
{
    public:
        E0() : State(0) {};
        bool transitionD(Automaton * automaton, Symbol * s);
        bool transitionRead(Automaton * automaton, Symbol * s);
		bool transitionWrite(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionConst(Automaton * automaton, Symbol * s);
		bool transitionVar(Automaton * automaton, Symbol * s);
};

#endif
