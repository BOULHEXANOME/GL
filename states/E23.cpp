#include "E23.h"


E23::E23()
{
    state = 23;
}

bool E23::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Symbol * e = automaton->popSymbol();
	Symbol * affectInstruct = automaton->popSymbol();
	Symbol * id = automaton->popSymbol();
	automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState(); 
    Symbol *i_prime = new Symbol(id, e, affectInstruct);
    i_prime->setType(I_PRIME);
	(*automaton->states.begin())->transition(automaton, i_prime);
	return true;
}

/*
bool transitionOpA(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E21());
	return true;
}

bool transitionPlus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E38());
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E39());
	return true;
}

*/
