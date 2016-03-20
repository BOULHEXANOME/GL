#include "E10.h"
/*#include "E17.h"

bool E10::transitionComma(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E17());
	return true;
}*/

bool E10::transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * dprime =  new Symbol(s1,s2);
	dprime->setType(D_PRIME);
	automaton->programFromLexer.push_front(s);
	automaton->popState();
	automaton->popState();
	(*automaton->currentState)->transition(automaton, dprime);
	return true;
}

E10::E10()
{
	this->state = 10;
}
