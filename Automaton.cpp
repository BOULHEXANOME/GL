//
// Created by hdelval on 08/03/16.
//

#include <iostream>
#include "Automaton.h"
#include "Symbols/Nonterminaux/Variable.h"
#include "Symbols/Nonterminaux/Number.h"
#include "Symbols/Nonterminaux/PlusExpression.h"
#include "Symbols/Nonterminaux/MultiplyExpression.h"
#include "Symbols/Nonterminaux/VarDeclare.h"
#include "Symbols/Terminaux/VarTerminal.h"
#include "Symbols/Terminaux/IdTerminal.h"
#include "Symbols/Terminaux/AffectDeclareTerminal.h"
#include "Symbols/Nonterminaux/MinusExpression.h"
#include "Symbols/Nonterminaux/AffectInstruct.h"
#include "Symbols/Terminaux/AffectInstructTerminal.h"
#include "Symbols/Terminaux/MultiplyTerminal.h"
#include "Symbols/Terminaux/DivideTerminal.h"
#include "Symbols/Terminaux/ParenthesisTerminal.h"
#include "Symbols/Terminaux/PlusTerminal.h"
#include "Symbols/Terminaux/MinusTerminal.h"
#include "Symbols/Nonterminaux/Parenthesis.h"
#include "exceptions.h"
#include "Symbols/Nonterminaux/Constant.h"
#include "Symbols/Nonterminaux/Write.h"
#include "Symbols/Nonterminaux/AffectConst.h"
#include "Symbols/Nonterminaux/Read.h"
#include "Symbols/Terminaux/Semicolon.h"
#include "Symbols/Terminaux/Dollar.h"
#include "Symbols/Terminaux/Comma.h"
#include "states/E0.h"
#include "Symbols/Terminaux/WriteTerminal.h"
#include "Symbols/Terminaux/ReadTerminal.h"
#include "Symbols/Terminaux/ConstTerminal.h"

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
    VarDeclare * declarationAction = new VarDeclare(declarationVar);
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

}


void Automaton::createSomeLines()
{
    // var myVar=10; => faux faux archifaux
    Line declaractionAfter = Line(Type::declaration);
    Variable *declarationVar = new Variable("myVar");
    var theVarDeclared;
    theVarDeclared.isIntancied = false;
    Number *toAffect = new Number(10);
    VarDeclare * declarationAction = new VarDeclare(declarationVar);
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
    Write *writeAction = new Write(new Variable("myVar"));
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

void Automaton::testStates5()
{
	//var i;
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);
	
	//i := 3 + 4 + 5;
    IdTerminal* idTerminal2 = new IdTerminal("i");
	idTerminal2->setType(ID);
	AffectInstructTerminal* affectInstruct = new AffectInstructTerminal();
	affectInstruct->setType(AFFECTINSTRUCT);
    Number* numberToAffect = new Number(3);
    numberToAffect->setType(VAL);
    PlusTerminal* plusTerminal = new PlusTerminal();
    plusTerminal->setType(PLUS);
    Number* numberToAffect2 = new Number(4);
    numberToAffect2->setType(VAL);
    MinusTerminal* plusTerminal2 = new MinusTerminal();
    plusTerminal2->setType(MINUS);
    Number* numberToAffect3 = new Number(5);
    numberToAffect3->setType(VAL);
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
    this->programFromLexer.push_front(numberToAffect3);
    this->programFromLexer.push_front(plusTerminal2); 
    this->programFromLexer.push_front(numberToAffect2);
    this->programFromLexer.push_front(plusTerminal); 
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

void Automaton::testStates3()
{
	//var i,j;
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Comma* comma = new Comma();
	comma->setType(COMMA);
    IdTerminal* idTerminal4 = new IdTerminal("j");
	idTerminal4->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);
	
	//i := 3;
    IdTerminal* idTerminal2 = new IdTerminal("j");
	idTerminal2->setType(ID);
	AffectInstructTerminal* affectInstruct = new AffectInstructTerminal();
	affectInstruct->setType(AFFECTINSTRUCT);
    Number* numberToAffect = new Number(4);
    numberToAffect->setType(VAL);
    Semicolon* semicolon2 = new Semicolon();
	semicolon2->setType(SEMICOLON);
    
	//ecrire i;	
    WriteTerminal* writeTerm = new WriteTerminal();
    writeTerm->setType(WRITE);
    IdTerminal* idTerminal3 = new IdTerminal("j");
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
    this->programFromLexer.push_front(idTerminal4);
    this->programFromLexer.push_front(comma);
    this->programFromLexer.push_front(idTerminal);
    this->programFromLexer.push_front(varTerminal);
    
    Symbol * sym = this->programFromLexer.front();
	this->programFromLexer.pop_front();
	
	DefaultState * e0 = new E0();
	this->states.push_front(e0);

	e0->transition(this, sym);
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
    Number* numberToAffect = new Number(4);
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
    /*
    this->programFromLexer.push_front(semicolon4);
    this->programFromLexer.push_front(idTerminal5);
    this->programFromLexer.push_front(affectInstruct2);
    this->programFromLexer.push_front(idTerminal4);*/
    
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


void Automaton::testStates4()
{
	//var i;
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);

	//var j;
	VarTerminal* varTerminal2 = new VarTerminal();
	varTerminal2->setType(VAR);
    IdTerminal* idTerminal2 = new IdTerminal("j");
	idTerminal2->setType(ID);
    Semicolon* semicolon2 = new Semicolon();
	semicolon2->setType(SEMICOLON);
	
	//i := 3;
    IdTerminal* idTerminal3 = new IdTerminal("i");
	idTerminal3->setType(ID);
	AffectInstructTerminal* affectInstruct = new AffectInstructTerminal();
	affectInstruct->setType(AFFECTINSTRUCT);
    Number* numberToAffect = new Number(3);
    numberToAffect->setType(VAL);
    Semicolon* semicolon3 = new Semicolon();
	semicolon3->setType(SEMICOLON);
    
    //i := j;
    IdTerminal* idTerminal4 = new IdTerminal("j");
	idTerminal4->setType(ID);
	AffectInstructTerminal* affectInstruct2 = new AffectInstructTerminal();
	affectInstruct2->setType(AFFECTINSTRUCT);
    IdTerminal* idTerminal7 = new IdTerminal("i");
	idTerminal7->setType(ID);
    Semicolon* semicolon4 = new Semicolon();
	semicolon4->setType(SEMICOLON);
    
	//ecrire i;	
    WriteTerminal* writeTerm = new WriteTerminal();
    writeTerm->setType(WRITE);
    IdTerminal* idTerminal5 = new IdTerminal("i");
	idTerminal5->setType(ID);
    Semicolon* semicolon5 = new Semicolon();
	semicolon5->setType(SEMICOLON);
	
	//ecrire j;	
    WriteTerminal* writeTerm2 = new WriteTerminal();
    writeTerm2->setType(WRITE);
    IdTerminal* idTerminal6 = new IdTerminal("j");
	idTerminal6->setType(ID);
    Semicolon* semicolon6 = new Semicolon();
	semicolon6->setType(SEMICOLON);
   
    //Fin de programme
    Dollar* dollar = new Dollar();
    dollar->setType(DOLLAR);
    
    this->programFromLexer.push_front(dollar);
  
    this->programFromLexer.push_front(semicolon6);
    this->programFromLexer.push_front(idTerminal6);
    this->programFromLexer.push_front(writeTerm2);
    
    this->programFromLexer.push_front(semicolon5);
    this->programFromLexer.push_front(idTerminal5);
    this->programFromLexer.push_front(writeTerm);
    
    this->programFromLexer.push_front(semicolon4);
    this->programFromLexer.push_front(idTerminal7);
    this->programFromLexer.push_front(affectInstruct2);
    this->programFromLexer.push_front(idTerminal4);
    
    this->programFromLexer.push_front(semicolon3);
    this->programFromLexer.push_front(numberToAffect);
    this->programFromLexer.push_front(affectInstruct);
    this->programFromLexer.push_front(idTerminal3);
    
    this->programFromLexer.push_front(semicolon2);
    this->programFromLexer.push_front(idTerminal2);
    this->programFromLexer.push_front(varTerminal2);
    
    this->programFromLexer.push_front(semicolon);
    this->programFromLexer.push_front(idTerminal);
    this->programFromLexer.push_front(varTerminal);	
    
    Symbol * sym = this->programFromLexer.front();
	this->programFromLexer.pop_front();
	
	DefaultState * e0 = new E0();
	this->states.push_front(e0);

	e0->transition(this, sym);
}

void Automaton::testStates6()
{
	//var i;
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);
	
	//i := (3);
    IdTerminal* idTerminal2 = new IdTerminal("i");
	idTerminal2->setType(ID);
	AffectInstructTerminal* affectInstruct = new AffectInstructTerminal();
	affectInstruct->setType(AFFECTINSTRUCT);
	ParenthesisTerminal * openParenthesis = new ParenthesisTerminal(TypeOfParenthesis::opening);
	openParenthesis->setType(OPENPARENTHESIS);
    Number* numberToAffect = new Number(3);
    numberToAffect->setType(VAL);
    ParenthesisTerminal * closeParenthesis = new ParenthesisTerminal(TypeOfParenthesis::closing);
	closeParenthesis->setType(CLOSEPARENTHESIS);
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
    this->programFromLexer.push_front(closeParenthesis);
    this->programFromLexer.push_front(numberToAffect);
    this->programFromLexer.push_front(openParenthesis);
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

bool Automaton::analyse()
{
    bool isCoherent = true;
    for(Program::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
    {
        isCoherent = (*cLineIterator).getTheSymbol()->analyse();
        if(!isCoherent)
            return isCoherent;
    }
    std::cout << "Program is coherent !" << std::endl;
    return isCoherent;
}

void Automaton::execute()
{
    this->clearTables();
    for(Program::const_iterator cLineIterator = this->programLines.begin() ; cLineIterator != this->programLines.end() ; ++cLineIterator)
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
        if(theConstants.find(theName) != theConstants.end())
        {
            std::cerr << "Error : cannot affect variable to a constant." << std::endl;
        }
        else
        {
            std::cerr << "Error affecting value to variable : variable has not been declared." << std::endl;
        }
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
        if(theConstants.find(theName) != theConstants.end())
        {
            toComplete->theValue = theConstants[theName];
            return true;
        }
        std::cerr << "Error accessing variable : variable has not been declared." << std::endl;
        return false;
    }
}

int Automaton::accessConstant(std::string theName) {
    if (theConstants.find(theName) != theConstants.end()) {
        return theConstants[theName];
    }
    else {
        std::cerr << "Error accessing constant : constant has not been declared (nor initialised)." << std::endl;
        throw CONST_DOES_NOT_EXISTS;
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
	this->programFromLexer.push_back(s);
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

void Automaton::testLire()
{
    // var i;
    // lire i;
    // ecrire i;
    VarTerminal* varTerminal = new VarTerminal();
    varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
    idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
    semicolon->setType(SEMICOLON);
    Semicolon* semicolon2 = new Semicolon();
    semicolon2->setType(SEMICOLON);
    Semicolon* semicolon3 = new Semicolon();
    semicolon3->setType(SEMICOLON);
    IdTerminal* idTerminal2 = new IdTerminal("i");
    idTerminal2->setType(ID);
    ReadTerminal* readTerminal = new ReadTerminal();
    readTerminal->setType(READ);
    IdTerminal* idTerminal3 = new IdTerminal("i");
    idTerminal3->setType(ID);
    WriteTerminal* writeTerm = new WriteTerminal();
    writeTerm->setType(WRITE);
    Dollar* dollar = new Dollar();
    dollar->setType(DOLLAR);

    this->programFromLexer.push_front(dollar);

    this->programFromLexer.push_front(semicolon3);
    this->programFromLexer.push_front(idTerminal3);
    this->programFromLexer.push_front(writeTerm);

    this->programFromLexer.push_front(semicolon2);
    this->programFromLexer.push_front(idTerminal2);
    this->programFromLexer.push_front(readTerminal);

    this->programFromLexer.push_front(semicolon);
    this->programFromLexer.push_front(idTerminal);
    this->programFromLexer.push_front(varTerminal);

    Symbol * sym = this->programFromLexer.front();
    this->programFromLexer.pop_front();

    DefaultState * e0 = new E0();
    this->states.push_front(e0);

    e0->transition(this, sym);
}

void Automaton::testConst()
{

    //const i=4;
    ConstTerminal* constTerminal = new ConstTerminal();
    constTerminal->setType(CONST);
    IdTerminal* idTerminal = new IdTerminal("i");
    idTerminal->setType(ID);
    AffectDeclareTerminal * equalDeclare = new AffectDeclareTerminal();
    equalDeclare->setType(AFFECTDECLARE);
    Number* numberToAffect = new Number(4);
    numberToAffect->setType(VAL);
    Semicolon* semicolon = new Semicolon();
    semicolon->setType(SEMICOLON);

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

    this->programFromLexer.push_front(semicolon);
    this->programFromLexer.push_front(numberToAffect);
    this->programFromLexer.push_front(equalDeclare);
    this->programFromLexer.push_front(idTerminal);
    this->programFromLexer.push_front(constTerminal);

    Symbol * sym = this->programFromLexer.front();
    this->programFromLexer.pop_front();

    DefaultState * e0 = new E0();
    this->states.push_front(e0);
    e0->transition(this, sym);
}


void Automaton::launchProgramFromLexer()
{
	Symbol * sym = this->programFromLexer.front();
    this->programFromLexer.pop_front();

    DefaultState * e0 = new E0();
    this->states.push_front(e0);
    e0->transition(this, sym);
}

void Automaton::testStates7()
{
	//var i;
	VarTerminal* varTerminal = new VarTerminal();
	varTerminal->setType(VAR);
    IdTerminal* idTerminal = new IdTerminal("i");
	idTerminal->setType(ID);
    Semicolon* semicolon = new Semicolon();
	semicolon->setType(SEMICOLON);
	
	//i := 3 * 4 / 2;
    IdTerminal* idTerminal2 = new IdTerminal("i");
	idTerminal2->setType(ID);
	AffectInstructTerminal* affectInstruct = new AffectInstructTerminal();
	affectInstruct->setType(AFFECTINSTRUCT);
    Number* numberToAffect = new Number(3);
    numberToAffect->setType(VAL);
    MultiplyTerminal* multiplyTerminal = new MultiplyTerminal();
    multiplyTerminal->setType(MULTIPLY);
    Number* numberToAffect2 = new Number(4);
    numberToAffect2->setType(VAL);
    DivideTerminal* divideTerminal = new DivideTerminal();
    divideTerminal->setType(DIVIDE);
    Number* numberToAffect3 = new Number(2);
    numberToAffect3->setType(VAL);
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
    this->programFromLexer.push_front(numberToAffect3);
    this->programFromLexer.push_front(divideTerminal); 
    this->programFromLexer.push_front(numberToAffect2);
    this->programFromLexer.push_front(multiplyTerminal); 
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

bool Automaton::analyseDeclareAndAffectConst(std::string theName)
{
    if(theVariables.find(theName) != theVariables.end() && theConstants.find(theName) != theConstants.end())
    {
        std::cerr << "Error declaring constant : name already exists" << std::endl;
        return false;
    }
    else
    {
        theConstants[theName] = -1;
        return true;
    }
}

bool Automaton::analyseDeclareVariable(std::string theName)
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

bool Automaton::analyseAffectVariable(std::string theName)
{
    if(theVariables.find(theName) != theVariables.end())
    {
        var newVariable;
        newVariable.theValue = -1;
        newVariable.isIntancied = true;
        theVariables[theName] = newVariable;
        return true;
    }
    else
    {
        if(theConstants.find(theName) != theConstants.end())
        {
            std::cerr << "Error : cannot affect variable to a constant." << std::endl;
        }
        else
        {
            std::cerr << "Error affecting value to variable : variable has not been declared." << std::endl;
        }
        return false;
    }
}

bool Automaton::analyseAccessVariable(std::string theName)
{
    if(theVariables.find(theName) != theVariables.end())
    {
        if(theVariables[theName].isIntancied)
        {
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
        if(theConstants.find(theName) != theConstants.end())
        {
            return true;
        }
        std::cerr << "Error accessing variable : variable has not been declared." << std::endl;
        return false;
    }
}

bool Automaton::analyseAccessConstant(std::string theName)
{
    if (theConstants.find(theName) != theConstants.end()) {
        return true;
    }
    else {
        std::cerr << "Error accessing constant : constant has not been declared (nor initialised)." << std::endl;
        throw CONST_DOES_NOT_EXISTS;
    }
}

void Automaton::optimize()
{
    for (Program::iterator cProgramLines = this->programLines.begin(); cProgramLines != this->programLines.end(); cProgramLines++)
    {
        cProgramLines->optimize();
    }
}

