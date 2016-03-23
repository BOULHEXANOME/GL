//
// Created by hdelval on 20/03/16.
//

#include "E5.h"
#include "E43.h"
#include "../Symbols/Terminaux/Semicolon.h"

E5::E5()
{
    expectedSymbols = ";";
    state = 5;
}

bool E5::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    automaton->pushState(semicolon, new E43());
    return true;
}

bool E5::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que le point virgule a été oublié, et continue donc avec le symbole ';'." << std::endl;

    // on simule une transition sur semicolon
    automaton->programFromLexer.push_front(unknown);
    Symbol * semicolon = new Semicolon();
    transitionSemicolon(automaton, semicolon);
    return true;
}
