#include "E42.h"
E42::E42()
{
	this->state = 42;
}
/*
bool transitionRead(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I(s3,s2,s1));
	return true;
}

bool transitionWrite(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I(s3,s2,s1));
	return true;
}

bool transitionId(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I(s3,s2,s1));
	return true;
}
*/
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
