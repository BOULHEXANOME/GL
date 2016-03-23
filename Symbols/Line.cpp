//
// Created by hdelval on 04/03/16.
//

#include <iostream>
#include "Line.h"
#include "../Automaton.h"

std::ostream & operator<<(std::ostream &os, const Line &line)
{
    os << line.theSymbol->print();
    return os;
}

void Line::execute() const
{
    theSymbol->execute();
}

void Line::addSymbol(Symbol *symbolsToAdd)
{
    theSymbol = symbolsToAdd;
    theSymbol->analyse();
}
