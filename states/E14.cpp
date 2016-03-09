#include "E14.h"

bool transitionT(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E29());
	return true;
}

bool transitionId(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E34());
	return true;
}

bool transitionVal(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E35());
	return true;
}

bool transitionOpenParenthesis(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E36());
	return true;
}

bool transitionE(Automaton * automaton, Symbol * s);{
	automaton->pushState(s, E23());
	return true;
}

bool transitionF(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E31());
	return true;
}
