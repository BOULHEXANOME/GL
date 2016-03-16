//
// Created by hdelval on 04/03/16.
//

#include <iostream>
#include "Line.h"

std::ostream & operator<<(std::ostream &os, const Line &line)
{
    for(Line::ListOfSymbols::const_iterator cSymbolIterator = line.symbols.begin() ; cSymbolIterator != line.symbols.end() ; ++cSymbolIterator)
    {
        os << (*cSymbolIterator)->print();
    }
    return os;
}


void Line::optimize() {
	for(Line::ListOfSymbols::const_iterator cSymbolIterator = line.symbols.begin() ; cSymbolIterator != line.symbols.end() ; ++cSymbolIterator)
	{
		cSymbolIterator->optimize();
	}
}
