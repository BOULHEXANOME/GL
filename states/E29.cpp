//
// Created by hdelval on 20/03/16.
//

#include "E29.h"

E29::E29()
{
    state = 29;
}

bool E29::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Symbol * t = automaton->popSymbol();
    t->setType(E);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, t);
    return true;
}
