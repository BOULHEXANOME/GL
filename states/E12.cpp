//
// Created by hdelval on 22/03/16.
//

#include "E12.h"
#include "E19.h"
#include "../Symbols/Terminaux/Comma.h"

E12::E12()
{
    expectedSymbols = "comma, ;";
    state = 12;
}

bool E12::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Symbol * aff = automaton->popSymbol();
    Symbol * constS = automaton->popSymbol();

    Symbol * dprime =  new Symbol();
    dprime->setType(D_PRIME);
    dprime->setColumnWhereSymbolOccurs(aff->getColumnWhereSymbolOccurs());
    dprime->setLineWhereSymbolOccurs(aff->getLineWhereSymbolOccurs());

    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, dprime);
    return true;
}

bool E12::transitionComma(Automaton * automaton, Symbol * comma) {
	automaton->pushState(comma, new E19());
	return true;
}

bool E12::transitionDefault(Automaton *automaton, Symbol *unknown)
{
    std::cerr << "Erreur syntaxique, symbole non attendu";
    automaton->printError(unknown);
    std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
    std::cerr << "L'automate assume que la virgule a été oubliée, et continue donc avec ce symbole." << std::endl;

    // on simule une transition sur comma
    automaton->programFromLexer.push_front(unknown);
    Symbol * comma = new Comma();
    transitionComma(automaton, comma);
    return true;
}
