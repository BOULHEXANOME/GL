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

bool E31::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(closeParenthesis);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionPlus(Automaton * automaton, Symbol * plus)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(plus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionMinus(Automaton * automaton, Symbol * minus)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(minus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionDivide(Automaton * automaton, Symbol * divide)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(divide);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionMultiply(Automaton * automaton, Symbol * multiply)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(multiply);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}
