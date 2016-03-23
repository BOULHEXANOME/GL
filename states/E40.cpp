//
// Created by hdelval on 20/03/16.
//

#include "E40.h"

#include "../Symbols/Terminaux/ParenthesisTerminal.h"
#include "../Symbols/Nonterminaux/Parenthesis.h"
#include "../Symbols/Nonterminaux/Expression.h"

E40::E40()
{
    state = 40;
}

bool E40::transitionWrite(Automaton *automaton, Symbol *write)
{
    Symbol * semicolon = automaton->popSymbol();
    Symbol * dPrime = automaton->popSymbol();
    Symbol * d = automaton->popSymbol();
    d->setType(D);
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

