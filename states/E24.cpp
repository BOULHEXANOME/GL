//
// Created by hdelval on 22/03/16.
//

#include "E24.h"
#include "E25.h"

E24::E24()
{
    state = 24;
}

bool E24::transitionVal(Automaton *automaton, Symbol *val)
{
    automaton->pushState(val, new E25());
    return true;
}

