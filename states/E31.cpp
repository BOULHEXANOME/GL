//
// Created by hdelval on 20/03/16.
//

#include "E31.h"

E31::E31()
{
    state = 31;
}

bool E31::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionCloseParenthesis(Automaton *automaton, Symbol *closeParenthesis)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(closeParenthesis);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}
