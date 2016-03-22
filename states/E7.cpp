//
// Created by hdelval on 22/03/16.
//

#include "E7.h"
#include "E16.h"

E7::E7()
{
    state = 7;
}

bool E7::transitionId(Automaton *automaton, Symbol *id)
{
    automaton->pushState(id, new E16());
    return true;
}
