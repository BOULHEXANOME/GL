//
// Created by hdelval on 22/03/16.
//

#include "E6.h"
#include "E8.h"
#include "../Symbols/Terminaux/Semicolon.h"
#include "../Symbols/Terminaux/IdTerminal.h"

bool E6::transitionId(Automaton *automaton, Symbol *id)
{
    automaton->pushState(id, new E8());
    return true;
}

E6::E6()
{
    expectedSymbols = "id";
    state = 6;
}

bool E6::transitionDefault(Automaton *automaton, Symbol *unknown)
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
