//
// Created by hdelval on 20/03/16.
//

#include "E40.h"

E40::E40()
{
    state = 40;
}

bool E40::transitionWrite(Automaton *automaton, Symbol *write)
{
    Symbol * semicolon = automaton->popSymbol();
    Symbol * dPrime = automaton->popSymbol();
    Symbol * d = automaton->popSymbol();
    // Symbol * id2 =  new Symbol(s1);
    d->setType(D);
    automaton->programFromLexer.push_front(write);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, d);
    return true;
}
