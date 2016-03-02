#ifndef E1_H
#define E1_H

#include "State.h"

class E1 : public State {
  public:
    E1() : State(1) {};
    bool transition(Automaton & automaton, std::shared_ptr<Symbol> s);
};

#endif
