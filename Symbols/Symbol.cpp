//
// Created by hdelval on 04/03/16.
//

#include "Symbol.h"

int Symbol::getType() const {
    return NON_TERMINAL;
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
