#include "E20.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"
#include "../Symbols/Nonterminaux/VarDeclare.h"

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
    VarDeclare * actionDeclareVariable = new VarDeclare(varDeclared);
    Line lineDeclaration = Line(Type::declaration);
    lineDeclaration.addSymbol(actionDeclareVariable);
    automaton->addProgramLine(lineDeclaration);
	
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
    VarDeclare * actionDeclareVariable = new VarDeclare(varDeclared);
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
