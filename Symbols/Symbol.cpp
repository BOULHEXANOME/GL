//
// Created by hdelval on 04/03/16.
//

#include "Symbol.h"
/*
int Symbol::getType() const {
    return symbolType;
}
*/
int Symbol::getType() const
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

int Symbol::execute() const
{
    std::cout << "Cannot execute abstract symbol class." << std::endl;
}

bool Symbol::analyse() const
{
    std::cout << "Cannot analyse abstract symbol class." << std::endl;
    return false;
}

void optimize()
{
    //do nothing
}
