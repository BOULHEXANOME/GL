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

#include "states/E0.h"
#include "states/E1.h"
#include "states/E2.h"
#include "states/E3.h"
/*#include "states/E4.h"
#include "states/E5.h"
#include "states/E6.h"
#include "states/E7.h"
#include "states/E8.h"
#include "states/E9.h"*/
#include "states/E10.h"/*
#include "states/E11.h"
#include "states/E12.h"
#include "states/E13.h"
#include "states/E14.h"*/
#include "states/E15.h"/*
#include "states/E16.h"
#include "states/E17.h"
#include "states/E18.h"
#include "states/E19.h"
#include "states/E20.h"
#include "states/E21.h"
#include "states/E22.h"
#include "states/E23.h"
#include "states/E24.h"
#include "states/E25.h"
#include "states/E26.h"
#include "states/E27.h"
#include "states/E28.h"
#include "states/E29.h"
#include "states/E30.h"
#include "states/E31.h"
#include "states/E32.h"
#include "states/E33.h"
#include "states/E34.h"
#include "states/E35.h"
#include "states/E36.h"
#include "states/E37.h"
#include "states/E38.h"
#include "states/E39.h"
#include "states/E40.h"
#include "states/E41.h"
#include "states/E42.h"
#include "states/E43.h"*/
#include "Symbols/Terminaux/WriteTerminal.h"

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
    // var myVar=10; => faux faux archifaux
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


void Automaton::testStates2()
{
	//var i;
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);
	
	//i := 3;
    IdTerminal* idTerminal2 = new IdTerminal("i");
	idTerminal2->setType(ID);
	AffectInstructTerminal* affectInstruct = new AffectInstructTerminal();
	affectInstruct->setType(AFFECTINSTRUCT);
    Number* numberToAffect = new Number(3);
    numberToAffect->setType(VAL);
    Semicolon* semicolon2 = new Semicolon();
	semicolon2->setType(SEMICOLON);
    
	//ecrire i;
    WriteTerminal* writeTerm = new WriteTerminal();
    writeTerm->setType(WRITE);
    IdTerminal* idTerminal3 = new IdTerminal("i");
	idTerminal3->setType(ID);
    Semicolon* semicolon3 = new Semicolon();
	semicolon3->setType(SEMICOLON);
    
    //Fin de programme
    Dollar* dollar = new Dollar();
    dollar->setType(DOLLAR);
    
    this->programFromLexer.push_front(dollar);
    
    this->programFromLexer.push_front(semicolon3);
    this->programFromLexer.push_front(idTerminal3);
    this->programFromLexer.push_front(writeTerm);
    
    this->programFromLexer.push_front(semicolon2);
    this->programFromLexer.push_front(numberToAffect);
    this->programFromLexer.push_front(affectInstruct);
    this->programFromLexer.push_front(idTerminal2);
    
    this->programFromLexer.push_front(semicolon);
    this->programFromLexer.push_front(idTerminal);
    this->programFromLexer.push_front(varTerminal);
    
    Symbol * sym = this->programFromLexer.front();
	this->programFromLexer.pop_front();
	
	DefaultState * e0 = new E0();
	this->states.push_front(e0);

	e0->transition(this, sym);
}

void Automaton::testStates()
{
	//var i;
	//ecrire 3;
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);
    Semicolon* semicolon2 = new Semicolon();
	semicolon2->setType(SEMICOLON);
    Number* numberToWrite = new Number(3);
    numberToWrite->setType(VAL);
    WriteTerminal* writeTerm = new WriteTerminal();
    writeTerm->setType(WRITE);
    Dollar* dollar = new Dollar();
    dollar->setType(DOLLAR);
    
    this->programFromLexer.push_front(dollar);
    this->programFromLexer.push_front(semicolon2);
    this->programFromLexer.push_front(numberToWrite);
    this->programFromLexer.push_front(writeTerm);
    this->programFromLexer.push_front(semicolon);
    this->programFromLexer.push_front(idTerminal);
    this->programFromLexer.push_front(varTerminal);
    
    Symbol * sym = this->programFromLexer.front();
	this->programFromLexer.pop_front();
	
	DefaultState * e0 = new E0();
	this->states.push_front(e0);

	e0->transition(this, sym);
}

void Automaton::printCode()
{
    for(Program::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
    {
        std::cout << (*cLineIterator) << ";" << std::endl;
    }
}

void Automaton::pushState(Symbol* s, DefaultState * e)
{
	
    std::cout << "push State : " << e->state<< std::endl;
	this->symbolsAutomaton.push_front(s);
	this->states.push_front(e);
	
	//TODO il faudra savoir si on push front/push back dans le programme renvoyé par le lexer
	Symbol * sym = this->programFromLexer.front();
	this->programFromLexer.pop_front();
	
    (*this->states.begin())->transition(this, sym);
}

void Automaton::pushSymbol(Symbol * s) {
	
	std::cout << "Push Symbol: " << s << std::endl;
	this->programFromLexer.push_front(s);
}

void Automaton::popState()
{
	this->states.pop_front();
	std::cout << "pop State, current State : " << states.front()->state<< std::endl;
}

Symbol * Automaton::popSymbol()
{
	Symbol * s = this->symbolsAutomaton.front();
	this->symbolsAutomaton.pop_front();
	return s;
}

void Automaton::accept()
{
	std::cout << "Youpi, ca marche !" << std::endl;
}
/*
void Automaton::printError(Symbol* problematicSymbol) {
	
	std::vector<std::String> stringsOfTheFile = lexer.getStringVector();
	std::cout << "Error : invalid symbol at line " << problematicSymbol->getLineWhereSymbolOccurs() << ", column " << problematicSymbol->getColumnWhereSymbolOccurs() << " :" << std::endl;
	std::cout << stringsOfTheFile[problematicSymbol->getLineWhereSymbolOccurs()] << std::endl;
	for (int i=0; i< problematicSymbol->getColumnWhereSymbolOccurs(); i++) {
		std::cout << " ";
	}
	std::cout << "^" << std::endl;
	
} */
