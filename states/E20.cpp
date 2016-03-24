#include "E20.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"
#include "../Symbols/Nonterminaux/VarDeclare.h"
#include "../Symbols/Terminaux/Semicolon.h"

bool E20::transitionSemicolon(Automaton * automaton, Symbol * semicolon)
{
	Symbol * id = automaton->popSymbol();
	Symbol * comma = automaton->popSymbol();
	Symbol * grosID = automaton->popSymbol();
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	IdTerminal * variableToDeclare = (IdTerminal*) (grosID);
    Variable * varDeclared = new Variable(variableToDeclare->getTheName());
    varDeclared->setColumnWhereSymbolOccurs(variableToDeclare->getColumnWhereSymbolOccurs());
    varDeclared->setLineWhereSymbolOccurs(variableToDeclare->getLineWhereSymbolOccurs());
    
    VarDeclare * actionDeclareVariable = new VarDeclare(varDeclared);
    actionDeclareVariable->setColumnWhereSymbolOccurs(varDeclared->getColumnWhereSymbolOccurs());
    actionDeclareVariable->setLineWhereSymbolOccurs(varDeclared->getLineWhereSymbolOccurs());
    
    Line lineDeclaration = Line(Type::declaration);
    lineDeclaration.addSymbol(actionDeclareVariable);
    automaton->addProgramLine(lineDeclaration);

	delete comma, grosID;
	
	id->setType(ID_LIST);
	automaton->programFromLexer.push_front(semicolon);
	
	(*automaton->states.begin())->transition(automaton, id);
	return true;
}

bool E20::transitionComma(Automaton * automaton, Symbol * comma)
{
	Symbol * id = automaton->popSymbol();
	Symbol * comma2 = automaton->popSymbol();
	Symbol * grosID = automaton->popSymbol();
	
	automaton->popState();
	automaton->popState();
	automaton->popState();
	
	IdTerminal * variableToDeclare = (IdTerminal*) (grosID);
    Variable * varDeclared = new Variable(variableToDeclare->getTheName());
    varDeclared->setColumnWhereSymbolOccurs(variableToDeclare->getColumnWhereSymbolOccurs());
    varDeclared->setLineWhereSymbolOccurs(variableToDeclare->getLineWhereSymbolOccurs());
    
    VarDeclare * actionDeclareVariable = new VarDeclare(varDeclared);
    actionDeclareVariable->setColumnWhereSymbolOccurs(varDeclared->getColumnWhereSymbolOccurs());
    actionDeclareVariable->setLineWhereSymbolOccurs(varDeclared->getLineWhereSymbolOccurs());
    
    Line lineDeclaration = Line(Type::declaration);
    lineDeclaration.addSymbol(actionDeclareVariable);
    automaton->addProgramLine(lineDeclaration);
	
	id->setType(ID_LIST);
	automaton->programFromLexer.push_front(comma);
	
	(*automaton->states.begin())->transition(automaton, id);
	return true;
}

E20::E20()
{
    state = 20;
	expectedSymbols = "comma,;";
}

bool E20::transitionDefault(Automaton *automaton, Symbol *unknown)
{
	std::cerr << "Erreur syntaxique, symbole non attendu";
	automaton->printError(unknown);
	std::cerr << "Un de ces symboles était attendu : [" << expectedSymbols << "]" << std::endl;
	std::cerr << "L'automate assume que le point virgule a été oublié, et continue donc avec ce symbole." << std::endl;

	// on simule une transition sur semicolon
	automaton->programFromLexer.push_front(unknown);
	Symbol * semicolon = new Semicolon();
	transitionSemicolon(automaton, semicolon);
	return true;
}
