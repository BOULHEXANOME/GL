#ifndef E0_H
#define E0_H

#include "State.h"

class E0 : public State
{
    public:
        E0() : State(0) {};
        bool transition(Automaton & automaton, std::shared_ptr<Symbol> s);
};

#endif
