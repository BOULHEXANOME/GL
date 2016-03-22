//
// Created by hdelval on 22/03/16.
//

#include "E28.h"

E28::E28()
{
    state = 28;
}

bool E28::transitionComma(Automaton *automaton, Symbol *comma)
{
    return DefaultState::transitionComma(automaton, comma);
}

bool E28::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    return DefaultState::transitionSemicolon(automaton, semicolon);
}
