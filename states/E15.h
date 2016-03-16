#ifndef E15_H
#define E15_H

#include "DefaultState.h"

class E15 : public DefaultState
{
    public:
        E15() : E15() {this->state = 15;};
		bool transitionSemilocon(Automaton * automaton, Symbol * s);
};

#endif
