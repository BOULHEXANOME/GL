//
// Created by hdelval on 20/03/16.
//

#include "E29.h"
#include "E32.h"
#include "E33.h"
#include "E30.h"

E29::E29()
{
    state = 29;
}

bool E29::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Symbol * t = automaton->popSymbol();
    t->setType(E);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, t);
    return true;
}

bool E29::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis)
{
    Symbol * t = automaton->popSymbol();
    t->setType(E);
    automaton->programFromLexer.push_front(closeParenthesis);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, t);
    return true;
}

bool E29::transitionPlus(Automaton * automaton, Symbol * plus)
{
    Symbol * t = automaton->popSymbol();
    t->setType(E);
    automaton->programFromLexer.push_front(plus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, t);
    return true;
}

bool E29::transitionMinus(Automaton * automaton, Symbol * minus)
{
    Symbol * t = automaton->popSymbol();
    t->setType(E);
    automaton->programFromLexer.push_front(minus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, t);
    return true;
}

bool E29::transitionDivide(Automaton * automaton, Symbol * divide)
{
	automaton->pushState(divide, new E33());
	return true;
}

bool E29::transitionMultiply(Automaton * automaton, Symbol * multiply)
{
	automaton->pushState(multiply, new E32());
	return true;
}

bool E29::transitionOpM(Automaton * automaton, Symbol * opm)
{
	automaton->pushState(opm, new E30());
	return true;
}
