//
// Created by hdelval on 08/03/16.
//

#include "Variable.h"
#include "Number.h"

int Variable::execute() const
{
    var* theStockageUnit = new var;
    if(! Automaton::instance().accessVariable(theName, theStockageUnit))
    {
        Automaton::instance().printError(this);
    }
    return theStockageUnit->theValue;
}

bool Variable::analyse()
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

Expression *Variable::optimizeExpression()
{
    setType(VAR);
    var* theStockageUnit = new var;
    if(Automaton::instance().accessVariable(theName, theStockageUnit, true))
    {
        return new Number(theStockageUnit->theValue);
    }
    return this;
}
