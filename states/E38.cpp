#include "E38.h"
#include "../Symbols/Nonterminaux/OpA.h"

bool E38::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(PLUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(id);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

bool E38::transitionVal(Automaton * automaton, Symbol * val) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(PLUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(val);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

bool E38::transitionOpeningParenthesis(Automaton * automaton, Symbol * openingParenthesis) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(PLUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(openingParenthesis);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

E38::E38()
{
    state = 38;
}
