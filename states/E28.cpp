//
// Created by hdelval on 22/03/16.
//

#include "E28.h"
#include "../Symbols/Nonterminaux/Number.h"
#include "../Symbols/Terminaux/IdTerminal.h"
#include "../Symbols/Nonterminaux/AffectConst.h"

E28::E28()
{
    state = 28;
}

bool E28::transitionComma(Automaton *automaton, Symbol *comma)
{
	Number * val = (Number*)automaton->popSymbol();
    Symbol * equal = automaton->popSymbol();
    IdTerminal * id = (IdTerminal*) automaton->popSymbol();
    automaton->popState();
    automaton->popState();
    automaton->popState();

    Number * valWithConst = new Number(val->getTheValue());
    AffectConst * actionDeclareAndAffectConst = new AffectConst(new Constant(id->getTheName()), valWithConst);
    Line affectAndDeclareConst(Type::declaration);
    affectAndDeclareConst.addSymbol(actionDeclareAndAffectConst);
    automaton->addProgramLine(affectAndDeclareConst);

    val->setType(AFF);
    
    Symbol * commaAff = automaton->popSymbol();
    Symbol * aff = automaton->popSymbol();
    automaton->popState();
    automaton->popState();
    
    automaton->programFromLexer.push_front(comma);
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}

bool E28::transitionSemicolon(Automaton *automaton, Symbol *semicolon)
{
    Number * val = (Number*)automaton->popSymbol();
    Symbol * equal = automaton->popSymbol();
    IdTerminal * id = (IdTerminal*) automaton->popSymbol();
    automaton->popState();
    automaton->popState();
    automaton->popState();

    Number * valWithConst = new Number(val->getTheValue());
    AffectConst * actionDeclareAndAffectConst = new AffectConst(new Constant(id->getTheName()), valWithConst);
    Line affectAndDeclareConst(Type::declaration);
    affectAndDeclareConst.addSymbol(actionDeclareAndAffectConst);
    automaton->addProgramLine(affectAndDeclareConst);

    val->setType(AFF);
    
    Symbol * commaAff = automaton->popSymbol();
    Symbol * aff = automaton->popSymbol();
    automaton->popState();
    automaton->popState();
    
    automaton->programFromLexer.push_front(semicolon);
    (*automaton->states.begin())->transition(automaton, val);
    return true;
}
