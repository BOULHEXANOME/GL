#include "E11.h"
#include "E14.h"

bool E11::transitionAffectInstruct(Automaton * automaton, Symbol * affectInstruct) {
	automaton->pushState(affectInstruct, new E14());
	return true;
}

E11::E11()
{
    state = 11;
}
