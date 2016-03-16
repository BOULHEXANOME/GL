#ifndef E43_H
#define E43_H

#include "DefaultState.h"

class E43 : public DefaultState
{
    public:
        E43() : State(43) {};
		bool transitionRead(Automaton * automaton, Symbol * s);
		bool transitionWrite(Automaton * automaton, Symbol * s);
		bool transitionId(Automaton * automaton, Symbol * s);
		bool transitionDollar(Automaton * automaton, Symbol * s);
};

#endif
