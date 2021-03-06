//
// Created by hdelval on 08/03/16.
//

#include "Write.h"

std::string Write::print() const
{
    return "ecrire " + toWrite->print();
}

int Write::execute() const
{
    std::cout << toWrite->execute() << std::endl;
    return 0;
}

bool Write::analyse()
{
    return toWrite->analyse();
}

bool Write::optimize()
{
    toWrite = toWrite->optimizeExpression();
    return false;
}
