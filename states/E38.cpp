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

bool E38::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis) {
	Symbol * plus = automaton->popSymbol();
	OpA * opA = new OpA();
	opA->setOp(PLUS);
	opA->setType(OPA);
	automaton->popState();
	automaton->programFromLexer.push_front(openParenthesis);
	(*automaton->states.begin())->transition(automaton,opA);
	return true;
}

E38::E38()
{
    state = 38;
}
