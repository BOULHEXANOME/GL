#ifndef E19_H
#define E19_H

#include "DefaultState.h"

class E19 : public DefaultState
{
    public:
        E19();
		virtual bool transitionId(Automaton * automaton, Symbol * id);
};

#endif
