//
// Created by hdelval on 08/03/16.
//

#include <iostream>
#include "Automaton.h"
#include "Symbols/Nonterminaux/Variable.h"
#include "Symbols/Nonterminaux/Number.h"
#include "Symbols/Nonterminaux/PlusExpression.h"
#include "Symbols/Nonterminaux/MultiplyExpression.h"
#include "Symbols/Nonterminaux/AffectVarDeclare.h"
#include "Symbols/Terminaux/VarTerminal.h"
#include "Symbols/Terminaux/IdTerminal.h"
#include "Symbols/Terminaux/AffectDeclareTerminal.h"
#include "Symbols/Nonterminaux/MinusExpression.h"
#include "Symbols/Nonterminaux/AffectInstruct.h"
#include "Symbols/Terminaux/AffectInstructTerminal.h"
#include "Symbols/Terminaux/MultiplyTerminal.h"
#include "Symbols/Terminaux/ParenthesisTerminal.h"
#include "Symbols/Terminaux/PlusTerminal.h"
#include "Symbols/Terminaux/MinusTerminal.h"
#include "Symbols/Nonterminaux/Parenthesis.h"
#include "Symbols/Terminaux/Semicolon.h"
#include "Symbols/Terminaux/Dollar.h"

#include "States/E0.h"
#include "States/E1.h"
#include "States/E2.h"
/*#include "States/E3.h"
#include "States/E4.h"
#include "States/E5.h"
#include "States/E6.h"
#include "States/E7.h"
#include "States/E8.h"
#include "States/E9.h"
#include "States/E10.h"
#include "States/E11.h"
#include "States/E12.h"
#include "States/E13.h"
#include "States/E14.h"*/
#include "States/E15.h"/*
#include "States/E16.h"
#include "States/E17.h"
#include "States/E18.h"
#include "States/E19.h"
#include "States/E20.h"
#include "States/E21.h"
#include "States/E22.h"
#include "States/E23.h"
#include "States/E24.h"
#include "States/E25.h"
#include "States/E26.h"
#include "States/E27.h"
#include "States/E28.h"
#include "States/E29.h"
#include "States/E30.h"
#include "States/E31.h"
#include "States/E32.h"
#include "States/E33.h"
#include "States/E34.h"
#include "States/E35.h"
#include "States/E36.h"
#include "States/E37.h"
#include "States/E38.h"
#include "States/E39.h"
#include "States/E40.h"
#include "States/E41.h"
#include "States/E42.h"
#include "States/E43.h"*/

void Automaton::createAndDeleteSomeLines()
{
    // create Line corresponding to :
    // var myVar=10;
    // before automaton (after lexer) :
    Line declaractionBefore;
    
    VarTerminal* varTerminal = new VarTerminal();
    AffectDeclareTerminal* equalSign = new AffectDeclareTerminal();
    Number* toAffect = new Number(10);
    declaractionBefore.addSymbol(varTerminal);
    declaractionBefore.addSymbol(equalSign);
    declaractionBefore.addSymbol(toAffect);
    // after automaton (ready to execute) :
    Line declaractionAfter = Line(Type::declaration);
    Variable *declarationVar = new Variable("myVar");
    // Number toAffect = Number(10); // already set
    AffectVarDeclare * declarationAction = new AffectVarDeclare(declarationVar, toAffect);
    declaractionAfter.addSymbol(declarationAction);

    // create Line corresponding to :
    // myVar := 5 * (1 + 3) - myVar;
    // before automaton (after lexer) :
    Line operationsBefore = Line();
    VarTerminal *varTerminal1 = new VarTerminal();
    AffectInstructTerminal *theAffectationSign = new AffectInstructTerminal();
    Number *numberFive = new Number(5);
    MultiplyTerminal *multSign = new MultiplyTerminal();
    ParenthesisTerminal *openingParenthesis = new ParenthesisTerminal(TypeOfParenthesis::opening);
    Number *numberOne = new Number(1);
    PlusTerminal *plusSymbol = new PlusTerminal();
    Number *numberThree = new Number(3);
    ParenthesisTerminal *closingParenthesis = new ParenthesisTerminal(TypeOfParenthesis::closing);
    MinusTerminal *minusSign = new MinusTerminal();
    VarTerminal *varTerminal2 = new VarTerminal(); // pour l'instant on ne sait pas que c'est la meme que au dessus
    operationsBefore.addSymbol(varTerminal1);
    operationsBefore.addSymbol(theAffectationSign);
    operationsBefore.addSymbol(numberFive);
    operationsBefore.addSymbol(multSign);
    operationsBefore.addSymbol(openingParenthesis);
    operationsBefore.addSymbol(numberOne);
    operationsBefore.addSymbol(plusSymbol);
    operationsBefore.addSymbol(numberThree);
    operationsBefore.addSymbol(closingParenthesis);
    operationsBefore.addSymbol(minusSign);
    operationsBefore.addSymbol(varTerminal2);
    // after automaton (ready to execute) :
    Line operationsAfter = Line(Type::instruction);
    Number *opRigthPlus = new Number(3);
    Number *opLeftPlus = new Number(1);
    Number *opLeftMult = new Number(5);
    Variable *varToSubstract = new Variable("myVar");
    PlusExpression *instructAdd = new PlusExpression(opLeftPlus, opRigthPlus);
    MultiplyExpression *instructMult = new MultiplyExpression(opLeftMult, instructAdd);
    MinusExpression *finalExpression = new MinusExpression(instructMult, varToSubstract);
    AffectInstruct *instructAffectResult = new AffectInstruct(varToSubstract, finalExpression);
    operationsAfter.addSymbol(instructAffectResult);


    for(std::list<Symbol*>::const_iterator i = operationsBefore.getSymbols().begin() ; i != operationsBefore.getSymbols().end() ; ++i)
    {
        std::cout << (*i)->getType() << std::endl;
    }
}


void Automaton::createSomeLines()
{
    // var myVar=10;
    Line declaractionAfter = Line(Type::declaration);
    Variable *declarationVar = new Variable("myVar");
    Number *toAffect = new Number(10); // already set
    AffectVarDeclare * declarationAction = new AffectVarDeclare(declarationVar, toAffect);
    declaractionAfter.addSymbol(declarationAction);

    // myVar := 5 * (1 + 3) - myVar;
    Line operationsAfter = Line(Type::instruction);
    Number *opRigthPlus = new Number(3);
    Number *opLeftPlus = new Number(1);
    Number *opLeftMult = new Number(5);
    Variable *varToSubstract = new Variable("myVar");
    PlusExpression *instructAdd = new PlusExpression(opLeftPlus, opRigthPlus);
    Parenthesis *parenthesisedExpr = new Parenthesis(instructAdd);
    MultiplyExpression *instructMult = new MultiplyExpression(opLeftMult, parenthesisedExpr);
    MinusExpression *finalExpression = new MinusExpression(instructMult, varToSubstract);
    AffectInstruct *instructAffectResult = new AffectInstruct(varToSubstract, finalExpression);
    operationsAfter.addSymbol(instructAffectResult);

    this->programLines.push_back(declaractionAfter);
    this->programLines.push_back(operationsAfter);
}


void Automaton::testStates()
{
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);
    Dollar* dollar = new Dollar();
    dollar->setType(DOLLAR);
    
    this->programme.push_front(dollar);
    this->programme.push_front(semicolon);
    this->programme.push_front(idTerminal);
    this->programme.push_front(varTerminal);
    
    Symbol * sym = this->programme.front();
	
	this->programme.pop_front();
	
	DefaultState * e0 = new E0();
	this->states.push_front(e0);
	this->CurrentState=e0;
	e0->transition(this, sym);
}

void Automaton::printCode()
{
    for(Programm::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
    {
        std::cout << (*cLineIterator) << ";" << std::endl;
    }
}

void Automaton::pushState(Symbol* s, DefaultState * e)
{
	
    std::cout << "push State : " << e->state<< std::endl;
	this->symbols.push_front(s);
	this->states.push_front(e);
	
	//TODO ici, un current state utilise a modifier peut etre
	this->CurrentState = e;
	
	//TODO il faudra savoir si on push front/push back dans le programme renvoyé par le lexer
	Symbol * sym = this->programme.front();
	this->programme.pop_front();
	
	//TODO ici, un current state utilise a modifier peut etre
	this->CurrentState->transition(this, sym);
}

void Automaton::popState()
{
	this->states.pop_front();
	//TODO ici, un current state utilise a modifier peut etre
	this->CurrentState = states.front();
}

Symbol * Automaton::popSymbol()
{
	Symbol * s = this->symbols.front();
	this->symbols.pop_front();
	return s;
}

void Automaton::accept()
{
	std::cout << "Youpi, ca marche !" << std::endl;
}
