#include "E26.h"
#include "E28.h"

bool E26::transitionVal(Automaton * automaton, Symbol * val) {
	automaton->pushState(val, new E28());
	return true;
}
E26::E26()
{
    state = 26;
}
