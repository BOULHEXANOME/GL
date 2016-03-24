#include "E23.h"
#include "E38.h"
#include "E39.h"
#include "E21.h"
#include "../Symbols/Nonterminaux/AffectInstruct.h"
#include "../Symbols/Nonterminaux/Expression.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Terminaux/Semicolon.h"


E23::E23()
{
    state = 23;
	expectedSymbols = "+, -, ;, additive or subtractive operator";
}

bool E23::transitionSemicolon(Automaton * automaton, Symbol * semicolon) {
	Expression * expr = (Expression*)automaton->popSymbol();
	Symbol * affectInstruct = automaton->popSymbol();
	Symbol * id = automaton->popSymbol();
	automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState(); 
    
    IdTerminal * variableToDeclare = (IdTerminal*) (id);
    Variable * varDeclared = new Variable(variableToDeclare->getTheName());
    varDeclared->setColumnWhereSymbolOccurs(variableToDeclare->getColumnWhereSymbolOccurs());
    varDeclared->setLineWhereSymbolOccurs(variableToDeclare->getLineWhereSymbolOccurs());
    
    AffectInstruct * actionInstruct = new AffectInstruct(varDeclared, expr);
    actionInstruct->setColumnWhereSymbolOccurs(varDeclared->getColumnWhereSymbolOccurs());
    actionInstruct->setLineWhereSymbolOccurs(varDeclared->getLineWhereSymbolOccurs());
    
    Line lineAffect = Line(Type::instruction);
    lineAffect.addSymbol(actionInstruct);
    automaton->addProgramLine(lineAffect);

	delete id, affectInstruct;

    expr->setType(I_PRIME);
	(*automaton->states.begin())->transition(automaton, expr);
	return true;
}


bool E23::transitionOpA(Automaton * automaton, Symbol * opa) {
	automaton->pushState(opa, new E21());
	return true;
}


bool E23::transitionPlus(Automaton * automaton, Symbol * plus) {
	automaton->pushState(plus, new E38());
	return true;
}

bool E23::transitionMinus(Automaton * automaton, Symbol * minus) {
	automaton->pushState(minus, new E39());
	return true;
}

bool E23::transitionDefault(Automaton *automaton, Symbol *unknown)
{
	std::cerr << "Erreur syntaxique, symbole non attendu";
	automaton->printError(unknown);
	std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
	std::cerr << "L'automate assume que le point virgule a été oublié, et continue donc avec le symbole ';'." << std::endl;

	// on simule une transition sur semicolon
	automaton->programFromLexer.push_front(unknown);
	Symbol * semicolon = new Semicolon();
	transitionSemicolon(automaton, semicolon);

	return true;
}
