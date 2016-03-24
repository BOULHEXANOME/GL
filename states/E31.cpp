//
// Created by hdelval on 20/03/16.
//

#include "E31.h"
#include "../Symbols/Terminaux/Semicolon.h"

E31::E31()
{
    state = 31;
    expectedSymbols = "*, /, ;, +, -, )";
}

bool E31::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(closeParenthesis);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionPlus(Automaton * automaton, Symbol * plus)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(plus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionMinus(Automaton * automaton, Symbol * minus)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(minus);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionDivide(Automaton * automaton, Symbol * divide)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(divide);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionMultiply(Automaton * automaton, Symbol * multiply)
{
    Symbol * f = automaton->popSymbol();
    f->setType(T);
    automaton->programFromLexer.push_front(multiply);
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, f);
    return true;
}

bool E31::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que le point virgule a été oublié, et continue donc avec le symbole ';'." << std::endl;

    // on simule une transition sur semicolon
    automaton->programFromLexer.push_front(unknown);
    Symbol * semicolon = new Semicolon();
    transitionSemicolon(automaton, semicolon);

    return true;
}
