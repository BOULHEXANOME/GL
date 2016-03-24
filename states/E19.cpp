#include "E19.h"
#include "E22.h"
#include "../Symbols/Terminaux/IdTerminal.h"

bool E19::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E22());
	return true;
}
E19::E19()
{
    state = 19;
}

bool E19::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que un identifiant a été oublié, et continue donc avec l'identifiant 'please_do_not_use_this_otherwise_you_gonna_have_some_trouble'." << std::endl;

    // on simule une transition sur id
    automaton->programFromLexer.push_front(unknown);
    Symbol * id = new IdTerminal("please_do_not_use_this_otherwise_you_gonna_have_some_trouble");
    transitionId(automaton, id);
    return true;
}
