#include "E34.h"

bool transitionMultiply(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionDivide(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionClosingParenthesis(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionPlus(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new F(s1));
	return true;
}
