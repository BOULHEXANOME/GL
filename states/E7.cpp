//
// Created by hdelval on 22/03/16.
//

#include "E7.h"
#include "E16.h"
#include "E12.h"
#include "../Symbols/Terminaux/IdTerminal.h"

E7::E7()
{
    state = 7;
    expectedSymbols = "id, one or many affectations";
}

bool E7::transitionId(Automaton *automaton, Symbol *id)
{
    automaton->pushState(id, new E16());
    return true;
}

bool E7::transitionAff(Automaton *automaton, Symbol *aff)
{
    automaton->pushState(aff, new E12());
    return true;
}

bool E7::transitionDefault(Automaton *automaton, Symbol *unknown)
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
