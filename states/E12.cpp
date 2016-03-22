//
// Created by hdelval on 22/03/16.
//

#include "E12.h"

E12::E12()
{
    state = 12;
}

bool E12::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Symbol * aff = automaton->popSymbol();
    Symbol * constS = automaton->popSymbol();

    Symbol * dprime =  new Symbol();
    dprime->setType(D_PRIME);

    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, dprime);
}
