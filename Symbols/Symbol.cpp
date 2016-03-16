//
// Created by hdelval on 04/03/16.
//

#include "Symbol.h"
/*
int Symbol::getType() const {
    return symbolType;
}
*/
int Symbol::getType()
{
	return this->symbolType;
}

void Symbol::setType(int T)
{
	this->symbolType = T;
}

std::ostream &operator<<(std::ostream &os, const Symbol &s)
{
    return os << s.print();
}

std::string Symbol::print() const
{
    return "unknown";
}


//TODO les constructos

Symbol::Symbol()
{
	
}

Symbol::Symbol(Symbol* s)
{
	
}

Symbol::Symbol(Symbol* s1, Symbol *s2)
{
	
}

Symbol::Symbol(Symbol *s1, Symbol *s2, Symbol *s3)
{
	
}

Symbol::Symbol(Symbol *s1, Symbol *s2, Symbol *s3, Symbol *s4)
{
	
}

Symbol::Symbol(Symbol *s1, Symbol *s2, Symbol *s3, Symbol *s4, Symbol *s5)
{
	
}
