#include "E43.h"

bool transitionRead(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I(s2,s1));
	return true;
}

bool transitionWrite(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I(s2,s1));
	return true;
}

bool transitionId(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I(s2,s1));
	return true;
}

bool transitionDollar(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new I(s2,s1));
	return true;
}
