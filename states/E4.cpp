//
// Created by hdelval on 20/03/16.
//

#include "E4.h"
#include "E40.h"
#include "../Symbols/Terminaux/Semicolon.h"

bool E4::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    automaton->pushState(semicolon, new E40());
    return true;
}

E4::E4()
{
    expectedSymbols = ";";
    state = 4;
}

bool E4::transitionDefault(Automaton *automaton, Symbol *unknown)
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
