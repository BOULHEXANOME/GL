#include "E14.h"
#include "E35.h"
#include "E31.h"
#include "E23.h"
#include "E29.h"

E14::E14()
{
    state = 14;
}

bool transitionVal(Automaton * automaton, Symbol * val){
	automaton->pushState(val, new E35());
	return true;
}

bool transitionF(Automaton * automaton, Symbol * f){
	automaton->pushState(f, new E31());
	return true;
}

bool transitionE(Automaton * automaton, Symbol * s);{
	automaton->pushState(s, new E23());
	return true;
}

bool transitionT(Automaton * automaton, Symbol * s){
	automaton->pushState(s, new E29());
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
