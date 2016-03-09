#include "E13.h"

bool transitionPlus(Automaton * automaton, Symbol * s){
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s3,s2,s1));
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s){
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s3,s2,s1));
	return true;
}

bool transitionMultiply(Automaton * automaton, Symbol * s){
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s3,s2,s1));
	return true;
}

bool transitionDivide(Automaton * automaton, Symbol * s){
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s3,s2,s1));
	return true;
}

bool transitionCloseParenthesis(Automaton * automaton, Symbol * s){
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s3,s2,s1));
	return true;
}

bool transitionSemilocon(Automaton * automaton, Symbol * s){
	Symbol * s1 = automaton->popSymbol();
	Symbol * s2 = automaton->popSymbol();
	Symbol * s3 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s3,s2,s1));
	return true;
}
