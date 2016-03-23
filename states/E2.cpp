#include "E2.h"
#include "E10.h"
#include "E15.h"
#include "../Symbols/Terminaux/IdTerminal.h"

bool E2::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E15());
	return true;
}

bool E2::transitionIdList(Automaton * automaton, Symbol * idList) {
	automaton->pushState(idList, new E10());
	return true;
}
E2::E2()
{
	expectedSymbols = "one or many id";
	this->state = 2;
}

bool E2::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que un identifiant a été oublié, et continue donc avec avec l'identifiant 'please_do_not_use_this_otherwise_you_gonna_have_some_trouble'." << std::endl;

    // on simule une transition sur ecrire
    automaton->programFromLexer.push_front(unknown);
    Symbol * id = new IdTerminal("please_do_not_use_this_otherwise_you_gonna_have_some_trouble");
    transitionId(automaton, id);
    return true;
}
