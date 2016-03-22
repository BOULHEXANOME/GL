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

bool E35::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis)
{
    Number * val = (Number*) automaton->popSymbol();
    val->setType(F);
    automaton->programFromLexer.push_front(closeParenthesis);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E35::transitionPlus(Automaton * automaton, Symbol * plus)
{
    Number * val = (Number*) automaton->popSymbol();
    val->setType(F);
    automaton->programFromLexer.push_front(plus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E35::transitionMinus(Automaton * automaton, Symbol * minus)
{
    Number * val = (Number*) automaton->popSymbol();
    val->setType(F);
    automaton->programFromLexer.push_front(minus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E35::transitionDivide(Automaton * automaton, Symbol * divide)
{
    Number * val = (Number*) automaton->popSymbol();
    val->setType(F);
    automaton->programFromLexer.push_front(divide);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E35::transitionMultiply(Automaton * automaton, Symbol * multiply)
{
    Number * val = (Number*) automaton->popSymbol();
    val->setType(F);
    automaton->programFromLexer.push_front(multiply);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}
