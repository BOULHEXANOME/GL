#include "E15.h"

bool E15::transitionSemilocon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new Symbol(s1));
	return true;
}
E15::E15()
{
	this->state = 15;
}
