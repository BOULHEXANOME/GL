#include "E14.h"
#include "E35.h"
#include "E31.h"
#include "E23.h"
#include "E29.h"
#include "E34.h"

E14::E14()
{
    state = 14;
}

bool E14::transitionVal(Automaton * automaton, Symbol * val){
	automaton->pushState(val, new E35());
	return true;
}

bool E14::transitionF(Automaton * automaton, Symbol * f){
	automaton->pushState(f, new E31());
	return true;
}

bool E14::transitionE(Automaton * automaton, Symbol * e){
	automaton->pushState(e, new E23());
	return true;
}

bool E14::transitionT(Automaton * automaton, Symbol * t){
	automaton->pushState(t, new E29());
	return true;
}

bool E14::transitionId(Automaton * automaton, Symbol * id){
	automaton->pushState(id, new E34());
	return true;
}

/*


bool transitionId(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E34());
	return true;
}


bool transitionOpenParenthesis(Automaton * automaton, Symbol * s){
	automaton->pushState(s, E36());
	return true;
}


*/
