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
#include "Symbols/Terminaux/AffectDeclareTerminal.h"
#include "Symbols/Nonterminaux/MinusExpression.h"
#include "Symbols/Nonterminaux/AffectInstruct.h"
#include "Symbols/Terminaux/AffectInstructTerminal.h"
#include "Symbols/Terminaux/MultiplyTerminal.h"
#include "Symbols/Terminaux/ParenthesisTerminal.h"
#include "Symbols/Terminaux/PlusTerminal.h"
#include "Symbols/Terminaux/MinusTerminal.h"
#include "Symbols/Nonterminaux/Parenthesis.h"


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

void Automaton::printCode()
{
    for(Programm::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
    {
        std::cout << (*cLineIterator) << ";" << std::endl;
    }
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
