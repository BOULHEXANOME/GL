#ifndef E15_H
#define E15_H

#include "DefaultState.h"

class E15 : public DefaultState
{
    public:
        E15();
        ~E15(){};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
