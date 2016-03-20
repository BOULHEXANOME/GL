//
// Created by hdelval on 20/03/16.
//

#include "E9.h"
#include "E35.h"
#include "E31.h"
#include "E29.h"
#include "E18.h"

E9::E9()
{
    state = 9;
}

bool E9::transitionVal(Automaton *automaton, Symbol *val) {
    automaton->pushState(val, new E35());
    return true;
}

bool E9::transitionF(Automaton *automaton, Symbol *f) {
    automaton->pushState(f, new E31());
    return true;
}

bool E9::transitionT(Automaton *automaton, Symbol *t) {
    automaton->pushState(t, new E29());
    return true;
}

bool E9::transitionE(Automaton *automaton, Symbol *e)
{
    automaton->pushState(e, new E18());
    return true;
}
