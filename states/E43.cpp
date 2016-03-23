//
// Created by hdelval on 20/03/16.
//

#include "E43.h"
#include "../Symbols/Terminaux/WriteTerminal.h"

E43::E43()
{
    state = 43;
    expectedSymbols = "read, write, id, endOfProgram";
}

bool E43::transitionDollar(Automaton *automaton, Symbol *dollar)
{
    Symbol * semicolonPopped = automaton->popSymbol();
    Symbol * iPrime = automaton->popSymbol();
    iPrime->setType(I);
    automaton->programFromLexer.push_front(dollar);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, iPrime);
    return true;
}

bool E43::transitionWrite(Automaton *automaton, Symbol *write)
{
    Symbol * semicolonPopped = automaton->popSymbol();
    Symbol * iPrime = automaton->popSymbol();
    iPrime->setType(I);
    automaton->programFromLexer.push_front(write);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, iPrime);
    return true;
}

bool E43::transitionRead(Automaton *automaton, Symbol *read)
{
    Symbol * semicolonPopped = automaton->popSymbol();
    Symbol * iPrime = automaton->popSymbol();
    iPrime->setType(I);
    automaton->programFromLexer.push_front(read);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, iPrime);
    return true;
}

bool E43::transitionId(Automaton *automaton, Symbol *id)
{
    Symbol * semicolonPopped = automaton->popSymbol();
    Symbol * iPrime = automaton->popSymbol();
    iPrime->setType(I);
    automaton->programFromLexer.push_front(id);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, iPrime);
    return true;
}

bool E43::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que un 'ecrire' a été oublié, et continue donc avec ce symbole." << std::endl;

    // on simule une transition sur ecrire
    automaton->programFromLexer.push_front(unknown);
    Symbol * ecrire = new WriteTerminal();
    transitionWrite(automaton, ecrire);
    return true;
}
