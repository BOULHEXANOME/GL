#include "E30.h"
#include "E34.h"
#include "E35.h"
#include "E36.h"
#include "E44.h"

bool E30::transitionId(Automaton * automaton, Symbol * id) {
	automaton->pushState(id, new E34());
	return true;
}

bool E30::transitionVal(Automaton * automaton, Symbol * val) {
	automaton->pushState(val, new E35());
	return true;
}

bool E30::transitionOpenParenthesis(Automaton * automaton, Symbol * openingParenthesis) {
	automaton->pushState(openingParenthesis, new E36());
	return true;
}

bool E30::transitionF(Automaton * automaton, Symbol * f) {
	automaton->pushState(f, new E44());
	return true;
}

E30::E30()
{
    state = 30;
}
