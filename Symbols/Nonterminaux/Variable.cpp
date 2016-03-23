//
// Created by hdelval on 08/03/16.
//

#include "Variable.h"

int Variable::execute() const
{
    var* theStockageUnit = new var;
    if(! Automaton::instance().accessVariable(theName, theStockageUnit))
    {
        Automaton::instance().printError(this);
    }
    return theStockageUnit->theValue;
}

bool Variable::analyse() const
{
    if(! Automaton::instance().analyseAccessVariable(theName))
    {
        Automaton::instance().printError(this);
        return false;
    }
    return true;
}

std::string Variable::print() const
{
    return theName;
}
