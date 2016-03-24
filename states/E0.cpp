#include "E0.h"
#include "E1.h"
#include "../symbolTypes.h"
#include "../Symbols/Terminaux/WriteTerminal.h"

bool E0::transitionD(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, new E1());
	return true;
}

bool E0::transitionRead(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programFromLexer.push_front(s);
	(*automaton->states.begin())->transition(automaton,s2);
	return true;
}

bool E0::transitionWrite(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programFromLexer.push_front(s);
	(*automaton->states.begin())->transition(automaton,s2);
	return true;
}

bool E0::transitionId(Automaton * automaton, Symbol * s) {
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programFromLexer.push_front(s);
	(*automaton->states.begin())->transition(automaton,s2);
	return true;
}

bool E0::transitionConst(Automaton * automaton, Symbol * s)
{
	Symbol * s2 =  new Symbol();
	s2->setType(D);
	automaton->programFromLexer.push_front(s);
	(*automaton->states.begin())->transition(automaton,s2);
	return true;
}

bool E0::transitionVar(Automaton * automaton, Symbol * s) {
	Symbol * declaration =  new Symbol();
	declaration->setType(D);
	automaton->programFromLexer.push_front(s);
	(*automaton->states.begin())->transition(automaton, declaration);
	return true;
}

E0::E0()
{
	this->state = 0;
	expectedSymbols = "declarative paragraph, read, write, id, var, const";
}

bool E0::transitionDefault(Automaton *automaton, Symbol *unknown)
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
