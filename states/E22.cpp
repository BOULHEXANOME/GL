#include "E22.h"
#include "E26.h"
#include "../Symbols/Terminaux/AffectDeclareTerminal.h"

bool E22::transitionAffectDeclare(Automaton * automaton, Symbol * affectDeclare) {
	automaton->pushState(affectDeclare, new E26());
	return true;
}

E22::E22()
{
    state = 22;
}

bool E22::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que un '=' a été oublié, et continue donc avec ce symbole." << std::endl;

    // on simule une transition sur =
    automaton->programFromLexer.push_front(unknown);
    Symbol * affectDeclare = new AffectDeclareTerminal();
    transitionAffectDeclare(automaton, affectDeclare);
    return true;
}
