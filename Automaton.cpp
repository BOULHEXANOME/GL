//
// Created by hdelval on 08/03/16.
//

#include <iostream>
#include "Automaton.h"
#include "exceptions.h"
#include "states/E0.h"

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
    if(theVariables.find(theName) != theVariables.end() || theConstants.find(theName) != theConstants.end())
    {
        std::cerr << "Erreur lors de la declaration de la variable : '"<< theName << "' existe déjà." << std::endl;
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
    if(theVariables.find(theName) != theVariables.end() || theConstants.find(theName) != theConstants.end())
    {
        std::cerr << "Erreur lors de la declaration de la constante : '"<< theName << "' existe déjà." << std::endl;
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
            std::cerr << "Erreur : impossible d'affecter une valeur à une constante." << std::endl;
        }
        else
        {
            std::cerr << "Erreur lors de l'affectation de la variable : '"<< theName << "', la variable n'a pas été déclarée." << std::endl;
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
            std::cerr << "Erreur lors de l'accès à la variable : '"<< theName << "', la variable n'a pas été instanciée." << std::endl;
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
        std::cerr << "Erreur lors de l'accès à la variable : '"<< theName << "', la variable n'a pas été déclarée." << std::endl;
        return false;
    }
}

int Automaton::accessConstant(std::string theName) {
    if (theConstants.find(theName) != theConstants.end()) {
        return theConstants[theName];
    }
    else {
        std::cerr << "Erreur d'accès à la constante : '" << theName << "' n'a pas été déclarée (ni initialisée)." << std::endl;
        throw CONST_DOES_NOT_EXISTS;
    }
}

void Automaton::pushState(Symbol* s, DefaultState * e)
{
	if(debug)
        std::cout << "push State : " << e->state<< std::endl;
	this->symbolsAutomaton.push_front(s);
	this->states.push_front(e);

	Symbol * sym = this->programFromLexer.front();
	this->programFromLexer.pop_front();
	
    (*this->states.begin())->transition(this, sym);
}


void Automaton::pushSymbol(Symbol * s)
{
	if(debug)
    	std::cout << "Push Symbol: " << s << std::endl;
	this->programFromLexer.push_back(s);

}

void Automaton::popState()
{
	this->states.pop_front();
	if(debug)
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
    if(debug)
    	std::cout << "Youpi, ca marche !" << std::endl;
}


void Automaton::printError(const Symbol* problematicSymbol) {
	
	std::cerr << " à la ligne " << problematicSymbol->getLineWhereSymbolOccurs() << ", colonne " << problematicSymbol->getColumnWhereSymbolOccurs() << " :" << std::endl;
	
	// -1 because vector first element is 0 while first line is 1
	std::cerr << stringsOfTheFile[problematicSymbol->getLineWhereSymbolOccurs() -1] << std::endl;
	for (int i=0; i< problematicSymbol->getColumnWhereSymbolOccurs(); i++) {
        std::cerr << " ";
	}
	std::cerr << "^" << std::endl;
	
}

void Automaton::launchProgramFromLexer()
{
	Symbol * sym = this->programFromLexer.front();
    this->programFromLexer.pop_front();

    DefaultState * e0 = new E0();
    this->states.push_front(e0);
    e0->transition(this, sym);
}

bool Automaton::analyseDeclareAndAffectConst(std::string theName)
{
    if(theVariables.find(theName) != theVariables.end() || theConstants.find(theName) != theConstants.end())
    {
        std::cerr << "Erreur lors de la declaration de la constante : '"<< theName << "' existe déjà." << std::endl;
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
    if(theVariables.find(theName) != theVariables.end() || theConstants.find(theName) != theConstants.end())
    {
        std::cerr << "Erreur lors de la declaration de la variable : '"<< theName << "' existe déjà." << std::endl;
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
            std::cerr << "Erreur : impossible d'affecter une valeur à une constante." << std::endl;
        }
        else
        {
            std::cerr << "Erreur lors de l'affectation de la variable : '"<< theName << "', la variable n'a pas été déclarée." << std::endl;
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
            std::cerr << "Erreur lors de l'accès à la variable : '"<< theName << "', la variable n'a pas été instanciée." << std::endl;
            return false;
        }
    }
    else
    {
        if(theConstants.find(theName) != theConstants.end())
        {
            return true;
        }
        std::cerr << "Erreur lors de l'accès à la variable : '"<< theName << "', la variable n'a pas été déclarée." << std::endl;
        return false;
    }
}

bool Automaton::analyseAccessConstant(std::string theName)
{
    if (theConstants.find(theName) != theConstants.end()) {
        return true;
    }
    else
    {
        std::cerr << "Erreur d'accès à la constante : '" << theName << "' n'a pas été déclarée (ni initialisée)." << std::endl;
        throw CONST_DOES_NOT_EXISTS;
    }
}

