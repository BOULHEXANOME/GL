#include "E21.h"

bool transitionVal(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E35());
	return true;
}

bool transitionId(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E34());
	return true;
}

bool transitionCloseParenthesis(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E36());
	return true;
}

bool transitionF(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E31());
	return true;
}

bool transitionT(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E27());
	return true;
}
