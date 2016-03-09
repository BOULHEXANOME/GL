#ifndef E11_H
#define E11_H

#include "DefaultState.h"

class E11 : public DefaultState
{
    public:
        E11() : State(11) {};
		bool transitionAffectInstruct(Automaton * automaton, Symbol * s);
};

#endif
