#include "E29.h"

bool transitionMultiply(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E32());
	return true;
}

bool transitionDivide(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E33());
	return true;
}

bool transitionOpM(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E30());
	return true;
}

bool transitionPlus(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new E(s1));
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new E(s1));
	return true;
}

bool transitionClosingParenthesis(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new E(s1));
	return true;
}

bool transitionSemicolon(Automaton * automaton, Symbol * s) {
	Symbol * s1 = automaton->popSymbol();
	automaton->CurrentState->transition(automaton,new E(s1));
	return true;
}
