#include "E23.h"
#include "../Symbols/Nonterminaux/AffectInstruct.h"
#include "../Symbols/Nonterminaux/Expression.h"
#include "../Symbols/Terminaux/IdTerminal.h"


E23::E23()
{
    state = 23;
}

bool E23::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Expression * expr = (Expression*)automaton->popSymbol();
	Symbol * affectInstruct = automaton->popSymbol();
	Symbol * id = automaton->popSymbol();
	automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState(); 
    
    // TODO faire remonter le I_prime
    IdTerminal * variableToDeclare = (IdTerminal*) (id);
    Variable * varDeclared = new Variable(variableToDeclare->getTheName());
    std::cout << std::endl << expr->getType() << std::endl<< std::endl;
    AffectInstruct * actionInstruct = new AffectInstruct(varDeclared, expr);
    Line lineAffect = Line(Type::instruction);
    lineAffect.addSymbol(actionInstruct);
    automaton->addProgramLine(lineAffect);
    
    expr->setType(I_PRIME);
	(*automaton->states.begin())->transition(automaton, expr);
	return true;
}

/*
bool transitionOpA(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E21());
	return true;
}

bool transitionPlus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E38());
	return true;
}

bool transitionMinus(Automaton * automaton, Symbol * s) {
	automaton->pushState(s, E39());
	return true;
}

*/
