#include "E39.h"

bool transitionId(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new OpA(s1));
	return true;
}

bool transitionVal(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new OpA(s1));
	return true;
}

bool transitionOpeningParenthesis(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new OpA(s1));
	return true;
}
