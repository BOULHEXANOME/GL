//
// Created by hdelval on 08/03/16.
//

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


void Automaton::createAndDeleteSomeLines()
{
    // create Line corresponding to :
    // var myVar=10;
    // before automaton (after lexer) :
    Line declaractionBefore = Line();
    VarTerminal varTerminal = VarTerminal();
    AffectDeclareTerminal equalSign = AffectDeclareTerminal();
    Number toAffect = Number(10);
    declaractionBefore.addSymbol(varTerminal);
    declaractionBefore.addSymbol(equalSign);
    declaractionBefore.addSymbol(toAffect);
    // after automaton (ready to execute) :
    Line declaractionAfter = Line(Type::declaration);
    Variable declarationVar = Variable("myVar");
    // Number toAffect = Number(10); // already set
    AffectVarDeclare declarationAction = AffectVarDeclare(declarationVar, toAffect);
    declaractionAfter.addSymbol(declarationAction);

    // create Line corresponding to :
    // myVar := 5 * (1 + 3) - myVar;
    // before automaton (after lexer) :
    Line operationsBefore = Line();
    VarTerminal varTerminal1 = VarTerminal();
    AffectInstructTerminal theAffectationSign = AffectInstructTerminal();
    Number numberFive = Number(5);
    MultiplyTerminal multSign = MultiplyTerminal();
    ParenthesisTerminal openingParenthesis = ParenthesisTerminal(TypeOfParenthesis::opening);
    Number numberOne = Number(1);
    PlusTerminal plusSymbol = PlusTerminal();
    Number numberThree = Number(3);
    ParenthesisTerminal closingParenthesis = ParenthesisTerminal(TypeOfParenthesis::closing);
    MinusTerminal minusSign = MinusTerminal();
    VarTerminal varTerminal2 = VarTerminal(); // pour l'instant on ne sait pas que c'est la meme que au dessus
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
    Number opRigthPlus = Number(3);
    Number opLeftPlus = Number(1);
    Number opLeftMult = Number(5);
    Variable varToSubstract = Variable("myVar");
    PlusExpression instructAdd = PlusExpression(opLeftPlus, opRigthPlus);
    MultiplyExpression instructMult = MultiplyExpression(opLeftMult, instructAdd);
    MinusExpression finalExpression = MinusExpression(instructMult, varToSubstract);
    AffectInstruct instructAffectResult = AffectInstruct(varToSubstract, finalExpression);
    operationsAfter.addSymbol(instructAffectResult);

}
