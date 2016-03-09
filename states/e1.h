#ifndef E1_H
#define E1_H

#include "DefaultState.h"

class E1 : public DefaultState
{
    public:
        E1() : State(1) {};
        bool transitionRead(Automaton & automaton, Symbol & s);
		bool transitionWrite(Automaton & automaton, Symbol & s);
		bool transitionId(Automaton & automaton, Symbol & s);
		bool transitionConst(Automaton & automaton, Symbol & s);
		bool transitionVar(Automaton & automaton, Symbol & s);
};

#endif
