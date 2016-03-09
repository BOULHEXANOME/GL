#ifndef DEFAULTSTATE_H
#define DEFAULTSTATE_H

#include "State.h"

class DefaultState : public State
{
    public:
        DefaultState() : State(-1) {};
        bool transition(Automaton & automaton, std::shared_ptr<Symbol> s);
};

#endif
