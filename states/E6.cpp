//
// Created by hdelval on 22/03/16.
//

#include "E6.h"
#include "E8.h"

bool E6::transitionId(Automaton *automaton, Symbol *id)
{
    automaton->pushState(id, new E8());
    return true;
}

E6::E6()
{
    expectedSymbols = "id";
    state = 6;
}
