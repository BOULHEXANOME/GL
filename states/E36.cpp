//
// Created by hdelval on 20/03/16.
//

#include "E36.h"
#include "E35.h"
#include "E31.h"
#include "../Symbols/Nonterminaux/Parenthesis.h"

E36::E36()
{
    state = 36;
}

bool E36::transitionVal(Automaton *automaton, Symbol *val)
{
    automaton->pushState(val, new E35());
	return true;
}

bool E36::transitionF(Automaton *automaton, Symbol *F)
{
    automaton->pushState(F, new E31());
	return true;
}

