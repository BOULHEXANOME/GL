//
// Created by hdelval on 20/03/16.
//

#include "E4.h"
#include "E40.h"

bool E4::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    automaton->pushState(semicolon, new E40());
    return true;
}

E4::E4()
{
    state = 4;
}
