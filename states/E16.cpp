//
// Created by hdelval on 22/03/16.
//

#include "E16.h"
#include "E24.h"
#include "../Symbols/Terminaux/AffectDeclareTerminal.h"

E16::E16()
{
    expectedSymbols = "=";
    state = 16;
}

bool E16::transitionAffectDeclare(Automaton *automaton, Symbol *equalSign)
{
    automaton->pushState(equalSign, new E24());
    return true;
}

bool E16::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que le '=' a été oublié, et continue donc avec ce symbole." << std::endl;

    // on simule une transition sur =
    automaton->programFromLexer.push_front(unknown);
    Symbol * equalSign = new AffectDeclareTerminal();
    transitionAffectDeclare(automaton, equalSign);
    return true;
}
