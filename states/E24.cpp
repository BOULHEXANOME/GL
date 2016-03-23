//
// Created by hdelval on 22/03/16.
//

#include "E24.h"
#include "E25.h"
#include "../Symbols/Nonterminaux/Number.h"

E24::E24()
{
    state = 24;
    expectedSymbols = "val";
}

bool E24::transitionVal(Automaton *automaton, Symbol *val)
{
    automaton->pushState(val, new E25());
    return true;
}

bool E24::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que une valeur a été oubliée, et continue donc avec la valeur 10." << std::endl;

    // on simule une transition sur =
    automaton->programFromLexer.push_front(unknown);
    Symbol * val = new Number(0);
    transitionVal(automaton, val);
    return true;
}
