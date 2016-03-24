#include "E42.h"
E42::E42()
{
	this->state = 42;
}


bool E42::transitionWrite(Automaton * automaton, Symbol * write) {
	Symbol * semicolon = automaton->popSymbol();
	Symbol * iprime = automaton->popSymbol();
	Symbol * i = automaton->popSymbol();
	
	automaton->programFromLexer.push_front(write);
    automaton->popState();
    automaton->popState();
    automaton->popState();
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
	(*automaton->states.begin())->transition(automaton, i);
	return true;
}
