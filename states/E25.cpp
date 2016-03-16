#include "E25.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new AffectDeclare(s3,s2,s1));
	return true;
}
