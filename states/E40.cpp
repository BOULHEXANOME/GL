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


bool E40::transitionVar(Automaton *automaton, Symbol *var)
{
	Symbol * semicolon = automaton->popSymbol();
    Symbol * dPrime = automaton->popSymbol();
    Symbol * d = automaton->popSymbol();
    d->setType(D);
    automaton->programFromLexer.push_front(var);
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

bool E40::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Symbol * f = automaton->popSymbol();
    Symbol * e = automaton->popSymbol();
    Symbol * f2 = automaton->popSymbol();
    f2->setType(F);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f2);
    return true;
}
