#include "E26.h"
#include "E28.h"
#include "../Symbols/Nonterminaux/Number.h"

bool E26::transitionVal(Automaton * automaton, Symbol * val) {
	automaton->pushState(val, new E28());
	return true;
}
E26::E26()
{
    state = 26;
}

bool E26::transitionDefault(Automaton *automaton, Symbol *unknown)
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
