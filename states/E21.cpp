#include "E21.h"
#include "E27.h"
#include "E31.h"
#include "E35.h"
#include "E36.h"

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
	automaton->pushState(s, new E34());
	return true;
}
*/
bool E21::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis){
	automaton->pushState(openParenthesis, new E36());
	return true;
}



E21::E21()
{
    state = 21;
}
