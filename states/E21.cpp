#include "E21.h"
#include "E27.h"
#include "E21.h"

bool E21::transitionVal(Automaton * automaton, Symbol * val){
	automaton->pushState(val, new E35());
	return true;
}

bool E21::transitionF(Automaton * automaton, Symbol * f){
	automaton->pushState(f, new E31());
	return true;
}

bool E21::transitionT(Automaton * automaton, Symbol * t){
	automaton->pushState(t, new E27());
	return true;
}
/*
bool E21::transitionId(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E34());
	return true;
}

bool E21::transitionCloseParenthesis(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E36());
	return true;
}


*/
E21::E21()
{
    state = 21;
}
