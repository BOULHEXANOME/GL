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
/*
#include "E1.h"
#include "E2.h"
#include "E3.h"
#include "E4.h"
#include "E5.h"
#include "E6.h"
#include "E7.h"
#include "E8.h"
#include "E9.h"
#include "E10.h"
#include "E11.h"
#include "E12.h"
#include "E13.h"
#include "E14.h"
#include "E15.h"
#include "E16.h"
#include "E17.h"
#include "E18.h"
#include "E19.h"
#include "E20.h"
#include "E21.h"
#include "E22.h"
#include "E23.h"
#include "E24.h"
#include "E25.h"
#include "E26.h"
#include "E27.h"
#include "E28.h"
#include "E29.h"
#include "E30.h"
#include "E31.h"
#include "E32.h"
#include "E33.h"
#include "E34.h"
#include "E35.h"
#include "E36.h"
#include "E37.h"
#include "E38.h"
#include "E39.h"
#include "E40.h"
#include "E41.h"
#include "E42.h"
#include "E43.h"*/

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
    IdTerminal* idTerminal = new IdTerminal("i");
    Semicolon* semicolon = new Semicolon();
    Dollar* dollar = new Dollar();
    
    
    this->programme.push_front(dollar);
    this->programme.push_front(semicolon);
    this->programme.push_front(idTerminal);
    this->programme.push_front(varTerminal);
    
    Symbol * sym = this->programme.front();
    std::cout << "punkt 1" << std::endl;
	this->programme.pop_front();
    std::cout << "punkt 2" << std::endl;
	DefaultState * e0 = new E0();
    std::cout << "punkt 3" << std::endl;
    this->pushState(sym, e0);
    std::cout << "punkt 4" << std::endl;
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
	this->symbols.push_front(s);
	this->states.push_front(e);
	
	//TODO ici, un current state utilise a modifier peut etre
	this->CurrentState = e;
	
	//TODO il faudra savoir si on push front/push back dans le programme renvoyé par le lexer
	Symbol * sym = this->programme.front();
	this->programme.pop_front();
	
	//this->CurrentState.transition(&Automaton::instance(), sym);
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
