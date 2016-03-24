#include "E39.h"
#include "../Symbols/Nonterminaux/OpA.h"

bool E39::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(MINUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(id);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

bool E39::transitionVal(Automaton * automaton, Symbol * val) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(MINUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(val);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

bool E39::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(MINUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(openParenthesis);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

E39::E39()
{
    state = 39;
}
