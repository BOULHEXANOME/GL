#ifndef STATE_H
#define STATE_H

#include <string>
#include <ostream>
#include <memory>
#include "../ast/symbol.h"
#include "../statemachine.h"

class State {
  public:
    State(int s) : state(s) {};
    virtual ~State() {};

    virtual bool transition(Automaton & automaton, std::shared_ptr<Symbol> s) = 0; // fction de transition entre les états
    int state() { return state; }

  protected:
    int state;
};

#endif
