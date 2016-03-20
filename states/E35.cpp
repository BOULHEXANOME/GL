//
// Created by hdelval on 20/03/16.
//

#include "E35.h"
#include "../Symbols/Nonterminaux/Number.h"

E35::E35()
{
    state = 35;
}

bool E35::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Number * val = (Number*) automaton->popSymbol();
    val->setType(F);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}
