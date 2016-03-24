//
// Created by hdelval on 20/03/16.
//

#include "E29.h"
#include "E32.h"
#include "E33.h"
#include "E30.h"
#include "../Symbols/Terminaux/Semicolon.h"

E29::E29()
{
    state = 29;
    expectedSymbols = "*, /, ;, +, -, ), multiplicative or dividing operation";
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

bool E29::transitionDefault(Automaton *automaton, Symbol *unknown) {
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
