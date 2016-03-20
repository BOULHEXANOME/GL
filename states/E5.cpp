//
// Created by hdelval on 20/03/16.
//

#include "E5.h"
#include "E43.h"

E5::E5()
{
    state = 5;
}

bool E5::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    automaton->pushState(semicolon, new E43());
    return true;
}
