#include "E34.h"

E34::E34()
{
    state = 34;
}

bool E34::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Symbol * id = automaton->popSymbol();
	automaton->programFromLexer.push_front(semicolon);
    automaton->popState(); 
    Symbol *f = new Symbol(id);
    f->setType(F);
	(*automaton->states.begin())->transition(automaton,f);
	return true;
}
/*
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
*/
