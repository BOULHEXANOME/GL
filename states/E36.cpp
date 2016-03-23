//
// Created by hdelval on 20/03/16.
//

#include "E36.h"
#include "E35.h"
#include "E31.h"
#include "E29.h"
#include "E37.h"
#include "E34.h"
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

bool E36::transitionId(Automaton *automaton, Symbol *id)
{
    automaton->pushState(id, new E34());
	return true;
}

bool E36::transitionF(Automaton *automaton, Symbol *F)
{
    automaton->pushState(F, new E31());
	return true;
}


bool E36::transitionT(Automaton *automaton, Symbol *T)
{
    automaton->pushState(T, new E29());
	return true;
}

bool E36::transitionE(Automaton *automaton, Symbol *E)
{
    automaton->pushState(E, new E37());
	return true;
}

bool E36::transitionOpenParenthesis(Automaton *automaton, Symbol *openParenthesis)
{
    automaton->pushState(openParenthesis, new E36());
	return true;
}

