//
// Created by hdelval on 22/03/16.
//

#include "E25.h"
#include "../Symbols/Nonterminaux/Number.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/AffectConst.h"
#include "../Symbols/Terminaux/Semicolon.h"

E25::E25()
{
    state = 25;
    expectedSymbols = "comma, ;";
}

bool E25::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Number * val = (Number*)automaton->popSymbol();
    Symbol * equal = automaton->popSymbol();
    IdTerminal * id = (IdTerminal*) automaton->popSymbol();

    Number * valWithConst = new Number(val->getTheValue());
    valWithConst->setColumnWhereSymbolOccurs(val->getColumnWhereSymbolOccurs());
    valWithConst->setLineWhereSymbolOccurs(val->getLineWhereSymbolOccurs());
    
    Constant* theConst = new Constant(id->getTheName());
    theConst->setColumnWhereSymbolOccurs(id->getColumnWhereSymbolOccurs());
    theConst->setLineWhereSymbolOccurs(id->getLineWhereSymbolOccurs());
    
    
    AffectConst * actionDeclareAndAffectConst = new AffectConst(theConst, valWithConst);
    actionDeclareAndAffectConst->setColumnWhereSymbolOccurs(theConst->getColumnWhereSymbolOccurs());
    actionDeclareAndAffectConst->setLineWhereSymbolOccurs(theConst->getLineWhereSymbolOccurs());
    
    Line affectAndDeclareConst(Type::declaration);
    affectAndDeclareConst.addSymbol(actionDeclareAndAffectConst);
    automaton->addProgramLine(affectAndDeclareConst);

    delete id, equal;

    val->setType(AFF);
    automaton->programFromLexer.push_front(semicolon);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E25::transitionComma(Automaton *automaton, Symbol *comma)
{
    Number * val = (Number*)automaton->popSymbol();
    Symbol * equal = automaton->popSymbol();
    IdTerminal * id = (IdTerminal*) automaton->popSymbol();

    Number * valWithConst = new Number(val->getTheValue());
    valWithConst->setColumnWhereSymbolOccurs(val->getColumnWhereSymbolOccurs());
    valWithConst->setLineWhereSymbolOccurs(val->getLineWhereSymbolOccurs());
    
    Constant* theConst = new Constant(id->getTheName());
    theConst->setColumnWhereSymbolOccurs(id->getColumnWhereSymbolOccurs());
    theConst->setLineWhereSymbolOccurs(id->getLineWhereSymbolOccurs());
    
    
    AffectConst * actionDeclareAndAffectConst = new AffectConst(theConst, valWithConst);
    actionDeclareAndAffectConst->setColumnWhereSymbolOccurs(theConst->getColumnWhereSymbolOccurs());
    actionDeclareAndAffectConst->setLineWhereSymbolOccurs(theConst->getLineWhereSymbolOccurs());
    
    Line affectAndDeclareConst(Type::declaration);
    affectAndDeclareConst.addSymbol(actionDeclareAndAffectConst);
    automaton->addProgramLine(affectAndDeclareConst);

    delete id, equal;

    val->setType(AFF);
    automaton->programFromLexer.push_front(comma);
    automaton->popState();
    automaton->popState();
    automaton->popState();
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E25::transitionDefault(Automaton *automaton, Symbol *unknown)
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
