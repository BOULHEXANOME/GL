//
// Created by hdelval on 22/03/16.
//

#include "E7.h"
#include "E16.h"
#include "E12.h"

E7::E7()
{
    state = 7;
}

bool E7::transitionId(Automaton *automaton, Symbol *id)
{
    automaton->pushState(id, new E16());
    return true;
}

bool E7::transitionAff(Automaton *automaton, Symbol *aff)
{
    automaton->pushState(aff, new E12());
    return true;
}
