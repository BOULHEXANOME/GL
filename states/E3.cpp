#include "E3.h"
#include "E9.h"
#include "E41.h"
#include "E11.h"
#include "E6.h"
#include "../Symbols/Terminaux/WriteTerminal.h"

bool E3::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E11());
	return true;
}

bool E3::transitionRead(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E6());
	return true;
}


bool E3::transitionI_Prime(Automaton * automaton, Symbol * iprime) {
	automaton->pushState(iprime, new E41());
	return true;
}

bool E3::transitionDollar(Automaton * automaton, Symbol * dollar) {
	automaton->accept();
	return true;
}

bool E3::transitionWrite(Automaton * automaton, Symbol * write) {
	automaton->pushState(write, new E9());
	return true;
}

E3::E3()
{
	expectedSymbols = "instructions paragraph, read, write, id, endOfProgramm";
	this->state = 3;
}

bool E3::transitionDefault(Automaton *automaton, Symbol *unknown)
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
