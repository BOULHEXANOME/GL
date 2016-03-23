//
// Created by hdelval on 22/03/16.
//

#include "E16.h"
#include "E24.h"

E16::E16()
{
    expectedSymbols = "=";
    state = 16;
}

bool E16::transitionAffectDeclare(Automaton *automaton, Symbol *equalSign)
{
    automaton->pushState(equalSign, new E24());
    return true;
}
