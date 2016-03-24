#include "E42.h"
#include "../Symbols/Terminaux/WriteTerminal.h"

E42::E42()
{
	this->state = 42;
	expectedSymbols = "read, write, id, endOfProgram";
}


bool E42::transitionWrite(Automaton * automaton, Symbol * write) {
	Symbol * semicolon = automaton->popSymbol();
	Symbol * iprime = automaton->popSymbol();
	Symbol * i = automaton->popSymbol();
	
	automaton->programFromLexer.push_front(write);
    automaton->popState();
    automaton->popState();
    automaton->popState();
	delete semicolon, iprime;
	(*automaton->states.begin())->transition(automaton, i);
	return true;
}

bool E42::transitionDollar(Automaton * automaton, Symbol * dollar) {
	Symbol * semicolon = automaton->popSymbol();
	Symbol * iprime = automaton->popSymbol();
	Symbol * i = automaton->popSymbol();
	
	automaton->programFromLexer.push_front(dollar);
    automaton->popState();
    automaton->popState();
    automaton->popState();
	delete semicolon, iprime;
	(*automaton->states.begin())->transition(automaton, i);
	return true;
	
}
bool E42::transitionRead(Automaton * automaton, Symbol * read) {
	Symbol * semicolon = automaton->popSymbol();
	Symbol * iprime = automaton->popSymbol();
	Symbol * i = automaton->popSymbol();
	
	automaton->programFromLexer.push_front(read);
    automaton->popState();
    automaton->popState();
    automaton->popState();
	delete semicolon, iprime;
	(*automaton->states.begin())->transition(automaton, i);
	return true;
}
bool E42::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * semicolon = automaton->popSymbol();
	Symbol * iprime = automaton->popSymbol();
	Symbol * i = automaton->popSymbol();
	
	automaton->programFromLexer.push_front(id);
    automaton->popState();
    automaton->popState();
    automaton->popState();
	delete semicolon, iprime;
	(*automaton->states.begin())->transition(automaton, i);
	return true;
}

bool E42::transitionDefault(Automaton *automaton, Symbol *unknown) {
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
