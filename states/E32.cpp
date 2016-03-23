#include "E32.h"
#include "../Symbols/Nonterminaux/OpM.h"

bool E32::transitionId(Automaton * automaton, Symbol * id) {
	Symbol * multiply = automaton->popSymbol();
	OpM * opM = new OpM();
	opM->setOp(MULTIPLY);
	opM->setType(OPM);
	automaton->popState();
	automaton->programFromLexer.push_front(id);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E32::transitionVal(Automaton * automaton, Symbol * val) {
	Symbol * multiply = automaton->popSymbol();
	OpM * opM = new OpM();
	opM->setOp(MULTIPLY);
	opM->setType(OPM);
	automaton->popState();
	automaton->programFromLexer.push_front(val);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

bool E32::transitionOpenParenthesis(Automaton * automaton, Symbol * openParenthesis) {
	Symbol * multiply = automaton->popSymbol();
	OpM * opM = new OpM();
	opM->setOp(MULTIPLY);
	opM->setType(OPM);
	automaton->popState();
	automaton->programFromLexer.push_front(openParenthesis);
	(*automaton->states.begin())->transition(automaton,opM);
	return true;
}

E32::E32()
{
    state = 32;
}
