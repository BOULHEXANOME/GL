#include "E10.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"
#include "../Symbols/Nonterminaux/AffectVarDeclare.h"
#include "E17.h"

bool E10::transitionComma(Automaton * automaton, Symbol * comma) {
	automaton->pushState(comma, new E17());
	return true;
}

bool E10::transitionSemicolon(Automaton * automaton, Symbol * s)
{
	Symbol * id = automaton->popSymbol();
	/*Symbol * var = */automaton->popSymbol();

    IdTerminal * variableToDeclare = (IdTerminal*) (id);
    Variable * varDeclared = new Variable(variableToDeclare->getTheName());
    AffectVarDeclare * actionDeclareVariable = new AffectVarDeclare(varDeclared);
    Line lineDeclaration = Line(Type::declaration);
    lineDeclaration.addSymbol(actionDeclareVariable);
    automaton->addProgramLine(lineDeclaration);

    Symbol * dprime =  new Symbol();
    dprime->setType(D_PRIME);
	automaton->programFromLexer.push_front(s);
	automaton->popState();
	automaton->popState();
	(*automaton->states.begin())->transition(automaton, dprime);
	return true;
}

E10::E10()
{
	this->state = 10;
}
