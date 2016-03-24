//
// Created by hdelval on 20/03/16.
//

#include "E37.h"
#include "E13.h"
#include "E39.h"
#include "E21.h"
#include "E38.h"
#include "../Symbols/Terminaux/MinusTerminal.h"


E37::E37()
{
    state = 37;
}

bool E37::transitionCloseParenthesis(Automaton * automaton, Symbol * closeParenthesis)
{
    automaton->pushState(closeParenthesis, new E13());
	return true;
}

bool E37::transitionMinus(Automaton * automaton, Symbol * minus)
{
    automaton->pushState(minus, new E39());
	return true;
}

bool E37::transitionPlus(Automaton * automaton, Symbol * plus)
{
    automaton->pushState(plus, new E38());
	return true;
}

bool E37::transitionOpA(Automaton * automaton, Symbol * opA)
{
    automaton->pushState(opA, new E21());
	return true;
}

bool E37::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que un '-' a été oublié, et continue donc avec avec ce symbole." << std::endl;

    // on simule une transition sur ecrire
    automaton->programFromLexer.push_front(unknown);
    Symbol * minus = new MinusTerminal();
    transitionMinus(automaton, minus);
    return true;
}
