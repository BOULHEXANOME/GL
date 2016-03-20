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
#include "exceptions.h"
#include "Symbols/Nonterminaux/Constant.h"
#include "Symbols/Nonterminaux/Write.h"
#include "Symbols/Nonterminaux/AffectConst.h"
#include "Symbols/Nonterminaux/Read.h"


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
    var theVarDeclared;
    theVarDeclared.isIntancied = false;
    Number *toAffect = new Number(10);
    AffectVarDeclare * declarationAction = new AffectVarDeclare(declarationVar, toAffect);
    declaractionAfter.addSymbol(declarationAction);

    // const myConst=5;
    Line declaractionConstAfter = Line(Type::declaration);
    Constant *declarationConst = new Constant("myConst");
    Number *toAffectConst = new Number(5);
    AffectConst * declarationConstAction = new AffectConst(declarationConst, toAffectConst);
    declaractionConstAfter.addSymbol(declarationConstAction);

    // ?? comment remplir les tables de symboles ???
    // TODO
    this->theVariables["myVar"] = theVarDeclared;
    this->theConstants["myConst"] = 5;

    // myVar := 5 * (1 + 4) - myVar;
    Line operationsAfter = Line(Type::instruction);
    Number *opRigthPlus = new Number(4);
    Number *opLeftPlus = new Number(1);
    Number *opLeftMult = new Number(5);
    Variable *varToSubstract = new Variable("myVar");
    PlusExpression *instructAdd = new PlusExpression(opLeftPlus, opRigthPlus);
    Parenthesis *parenthesisedExpr = new Parenthesis(instructAdd);
    MultiplyExpression *instructMult = new MultiplyExpression(opLeftMult, parenthesisedExpr);
    MinusExpression *finalExpression = new MinusExpression(instructMult, varToSubstract);
    AffectInstruct *instructAffectResult = new AffectInstruct(varToSubstract, finalExpression);
    operationsAfter.addSymbol(instructAffectResult);

    // write myVar;
    Line writeVar = Line(Type::instruction);
    Write *writeAction = new Write(new StockageUnit("myVar"));
    writeVar.addSymbol(writeAction);

    // read myVar;
    Line readVar = Line(Type::instruction);
    Read *readAction = new Read(new Variable("myVar"));
    readVar.addSymbol(readAction);

    this->programLines.push_back(declaractionAfter);
    this->programLines.push_back(declaractionConstAfter);
    this->programLines.push_back(writeVar);
    this->programLines.push_back(operationsAfter);
    this->programLines.push_back(writeVar);
    this->programLines.push_back(readVar);
    this->programLines.push_back(writeVar);
}

void Automaton::printCode()
{
    for(Programm::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
    {
        std::cout << (*cLineIterator) << ";" << std::endl;
    }
}

void Automaton::analyse()
{
    for(Programm::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
    {
        // TODO
    }
}

void Automaton::execute()
{
    this->clearTables();
    for(Programm::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
    {
        cLineIterator->execute();
    }

}

void Automaton::clearTables()
{
    this->theConstants.clear();
    this->theVariables.clear();
}

bool Automaton::declareVariable(std::string theName)
{
    if(theVariables.find(theName) != theVariables.end() && theConstants.find(theName) != theConstants.end())
    {
        std::cerr << "Error declaring variable : name already exists" << std::endl;
        return false;
    }
    else
    {
        var newVariable;
        newVariable.isIntancied = false;
        theVariables[theName] = newVariable;
        return true;
    }
}

bool Automaton::declareAndAffectConst(std::string theName, int theValue)
{
    if(theVariables.find(theName) != theVariables.end() && theConstants.find(theName) != theConstants.end())
    {
        std::cerr << "Error declaring constant : name already exists" << std::endl;
        return false;
    }
    else
    {
        theConstants[theName] = theValue;
        return true;
    }
}

bool Automaton::affectVariable(std::string theName, int theValue)
{
    if(theVariables.find(theName) != theVariables.end())
    {
        var newVariable;
        newVariable.theValue = theValue;
        newVariable.isIntancied = true;
        theVariables[theName] = newVariable;
        return true;
    }
    else
    {
        std::cerr << "Error affecting value to variable : variable has not been declared." << std::endl;
        return false;
    }
}

bool Automaton::accessVariable(std::string theName, var * toComplete)
{
    if(theVariables.find(theName) != theVariables.end())
    {
        if(theVariables[theName].isIntancied)
        {
            *toComplete = theVariables[theName];
            return true;
        }
        else
        {
            std::cerr << "Error accessing variable : variable has not been instancied yet." << std::endl;
            return false;
        }
    }
    else
    {
        std::cerr << "Error accessing variable : variable has not been declared." << std::endl;
        return false;
    }
}

int Automaton::accessConstant(std::string theName)
{
    if(theConstants.find(theName) != theConstants.end())
    {
        return theConstants[theName];
    }
    else
    {
        std::cerr << "Error accessing constant : constant has not been declared (nor initialised)." << std::endl;
        throw CONST_DOES_NOT_EXISTS;
    }
}
