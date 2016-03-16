#include "E15.h"

bool E15::transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	Symbol * id =  new Symbol(s1);
	id->setType(ID_LISTE);
	automaton->programme.push_front(s);
	automaton->popState();
	automaton->CurrentState->transition(automaton,id);
	return true;
}
E15::E15()
{
	this->state = 15;
}
