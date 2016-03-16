#include "E28.h"

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	Symbol * s4 = automaton->popSymbol();
	Symbol * s5 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new AffectDeclare(s5,s4,s3,s2,s1));
	return true;
}
