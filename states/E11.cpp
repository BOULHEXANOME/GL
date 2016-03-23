#include "E11.h"
#include "E14.h"
#include "../Symbols/Nonterminaux/AffectInstruct.h"
#include "../Symbols/Terminaux/AffectInstructTerminal.h"

bool E11::transitionAffectInstruct(Automaton * automaton, Symbol * affectInstruct) {
	automaton->pushState(affectInstruct, new E14());
	return true;
}

E11::E11()
{
	expectedSymbols = ":=";
    state = 11;
}

bool E11::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que le ':=' a été oublié, et continue donc avec ce symbole." << std::endl;

    // on simule une transition sur :=
    automaton->programFromLexer.push_front(unknown);
    Symbol * affectInstruct = new AffectInstructTerminal();
    transitionAffectInstruct(automaton, affectInstruct);
    return true;
}
