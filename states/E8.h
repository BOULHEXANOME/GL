#ifndef E8_H
#define E8_H

#include "DefaultState.h"

class E8 : public DefaultState
{
    public:
        E8() : State(8) {};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
