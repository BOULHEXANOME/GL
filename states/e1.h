#ifndef E1_H
#define E1_H

#include "DefaultState.h"

class E1 : public DefaultState
{
    public:
        E1() : State(1) {};
        bool transitionRead();
		bool transitionWrite();
		bool transitionId();
		bool transitionConst();
		bool transitionVar();
};

#endif
