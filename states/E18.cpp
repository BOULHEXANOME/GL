//
// Created by hdelval on 20/03/16.
//

#include "E18.h"
#include "E21.h"
#include "E38.h"
#include "E39.h"
#include "../Symbols/Nonterminaux/Write.h"
#include "../Symbols/Terminaux/Semicolon.h"

E18::E18()
{
    expectedSymbols = "+, -, ;, additive or subtractive operation";
    state = 18;
}

bool E18::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Expression * e = (Expression*) automaton->popSymbol();
    Symbol * write = automaton->popSymbol();

    Write* writeInstruction = new Write(e);
    
    Line writeInstruct(Type::instruction);
    writeInstruct.addSymbol(writeInstruction);
    automaton->addProgramLine(writeInstruct);

    e->setType(I_PRIME);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, e);
    return true;
}

bool E18::transitionOpA(Automaton * automaton, Symbol * opa){
	automaton->pushState(opa, new E21());
	return true;
}

bool E18::transitionPlus(Automaton * automaton, Symbol * plus){
	automaton->pushState(plus, new E38());
	return true;
}

bool E18::transitionMinus(Automaton * automaton, Symbol * minus){
	automaton->pushState(minus, new E39());
	return true;
}

bool E18::transitionDefault(Automaton *automaton, Symbol *unknown)
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
