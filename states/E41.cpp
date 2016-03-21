#include "E41.h"
#include "E42.h"

bool E41::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	automaton->pushState(semicolon, new E42());
	return true;
}
E41::E41()
{
	this->state = 41;
}
