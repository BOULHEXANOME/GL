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
    d->setType(D);//A quoi ca sert ?? et ou est instancié le D avec ses symboles dedans ???
    automaton->programFromLexer.push_front(write);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, d);
    return true;
}

bool E40::transitionId(Automaton *automaton, Symbol *id)
{
    Symbol * semicolon = automaton->popSymbol();
    Symbol * dPrime = automaton->popSymbol();
    Symbol * d = automaton->popSymbol();
    d->setType(D);
    automaton->programFromLexer.push_front(id);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, d);
    return true;
}

bool E40::transitionRead(Automaton *automaton, Symbol *read)
{
    Symbol * semicolon = automaton->popSymbol();
    Symbol * dPrime = automaton->popSymbol();
    Symbol * d = automaton->popSymbol();
    d->setType(D);
    automaton->programFromLexer.push_front(read);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, d);
    return true;
}

bool E40::transitionConst(Automaton *automaton, Symbol *constantS)
{
    Symbol * semicolon = automaton->popSymbol();
    Symbol * dPrime = automaton->popSymbol();
    Symbol * d = automaton->popSymbol();
    d->setType(D);
    automaton->programFromLexer.push_front(constantS);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, d);
    return true;
}
