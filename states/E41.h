#ifndef E41_H
#define E41_H

#include "DefaultState.h"

class E41 : public DefaultState
{
    public:
		E41();
		~E41(){};
		bool transitionSemicolon(Automaton * automaton, Symbol * s);
};

#endif
