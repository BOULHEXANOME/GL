//
// Created by hdelval on 04/03/16.
//

#include <iostream>
#include "Line.h"
#include "../Automaton.h"

std::ostream & operator<<(std::ostream &os, const Line &line)
{
    for(Line::ListOfSymbols::const_iterator cSymbolIterator = line.symbols.begin() ; cSymbolIterator != line.symbols.end() ; ++cSymbolIterator)
    {
        os << (*cSymbolIterator)->print();
    }
    return os;
}

void Line::execute() const
{
    for(Line::ListOfSymbols::const_iterator cSymbolIterator = symbols.begin() ; cSymbolIterator != symbols.end() ; ++cSymbolIterator)
    {

        (*cSymbolIterator)->execute();
    }

}
