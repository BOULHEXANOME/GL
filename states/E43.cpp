//
// Created by hdelval on 20/03/16.
//

#include "E43.h"

E43::E43()
{
    state = 43;
}

bool E43::transitionDollar(Automaton *automaton, Symbol *dollar)
{
    Symbol * semicolonPopped = automaton->popSymbol();
    Symbol * iPrime = automaton->popSymbol();
    iPrime->setType(I);
    automaton->programFromLexer.push_front(dollar);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, iPrime);
    return true;
}
