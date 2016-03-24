//
// Created by hdelval on 20/03/16.
//

#include "E35.h"
#include "../Symbols/Nonterminaux/Number.h"
#include "../Symbols/Terminaux/Semicolon.h"

E35::E35()
{
    state = 35;
    expectedSymbols = "*, /, ;, +, -, )";
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

bool E35::transitionDefault(Automaton *automaton, Symbol *unknown)
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
