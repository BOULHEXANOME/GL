#include "E34.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"

E34::E34()
{
    state = 34;
	expectedSymbols = "*, /, ;, +, -, )";
}

bool E34::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	IdTerminal * id = (IdTerminal*)automaton->popSymbol();
	Variable* variable = new Variable(id->getTheName());
	variable->setType(F);
	automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    
	(*automaton->states.begin())->transition(automaton, variable);
	return true;
}

bool E34::transitionMultiply(Automaton * automaton, Symbol * multiply) {
	IdTerminal * id = (IdTerminal*)automaton->popSymbol();
	Variable* variable = new Variable(id->getTheName());
	variable->setType(F);
	automaton->programFromLexer.push_front(multiply);
    automaton->popState();
    
	(*automaton->states.begin())->transition(automaton, variable);
	return true;
}

bool E34::transitionDivide(Automaton * automaton, Symbol * divide) {
	IdTerminal * id = (IdTerminal*)automaton->popSymbol();
	Variable* variable = new Variable(id->getTheName());
	variable->setType(F);
	automaton->programFromLexer.push_front(divide);
    automaton->popState();
    
	(*automaton->states.begin())->transition(automaton, variable);
	return true;
}

bool E34::transitionCloseParenthesis(Automaton * automaton, Symbol * closingParenthesis) {
	IdTerminal * id = (IdTerminal*)automaton->popSymbol();
	Variable* variable = new Variable(id->getTheName());
	variable->setType(F);
	automaton->programFromLexer.push_front(closingParenthesis);
    automaton->popState();
    
	(*automaton->states.begin())->transition(automaton, variable);
	return true;
}

bool E34::transitionPlus(Automaton * automaton, Symbol * plus) {
	IdTerminal * id = (IdTerminal*)automaton->popSymbol();
	Variable* variable = new Variable(id->getTheName());
	variable->setType(F);
	automaton->programFromLexer.push_front(plus);
    automaton->popState();
    
	(*automaton->states.begin())->transition(automaton, variable);
	return true;
}

bool E34::transitionMinus(Automaton * automaton, Symbol * minus) {
	IdTerminal * id = (IdTerminal*)automaton->popSymbol();
	Variable* variable = new Variable(id->getTheName());
	variable->setType(F);
	automaton->programFromLexer.push_front(minus);
    automaton->popState();
    
	(*automaton->states.begin())->transition(automaton, variable);
	return true;
}

