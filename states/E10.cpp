#include "E10.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/Variable.h"
#include "../Symbols/Nonterminaux/VarDeclare.h"
#include "E17.h"
#include "../Symbols/Terminaux/Semicolon.h"

bool E10::transitionComma(Automaton * automaton, Symbol * comma) {
	automaton->pushState(comma, new E17());
	return true;
}

bool E10::transitionSemicolon(Automaton * automaton, Symbol * s)
{
	Symbol * id = automaton->popSymbol();
	automaton->popSymbol();

    IdTerminal * variableToDeclare = (IdTerminal*) (id);
    Variable * varDeclared = new Variable(variableToDeclare->getTheName());
    VarDeclare * actionDeclareVariable = new VarDeclare(varDeclared);
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
	expectedSymbols = "one or many id, ;";
	this->state = 10;
}

bool E10::transitionDefault(Automaton *automaton, Symbol *unknown)
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
