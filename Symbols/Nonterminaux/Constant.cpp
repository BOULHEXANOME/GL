//
// Created by hdelval on 08/03/16.
//

#include "Constant.h"
#include "Number.h"

int Constant::execute() const
{
    var* theStockageUnit = new var;
    if(! Automaton::instance().accessVariable(theName, theStockageUnit))
    {
        Automaton::instance().printError(this);
    }
    return theStockageUnit->theValue;
}

std::string Constant::print() const
{
    return theName;
}

bool Constant::analyse()
{
    return Automaton::instance().analyseAccessConstant(theName);
}

int Constant::getType()
{
    return CONST;
}

Expression *Constant::optimizeExpression()
{
    setType(CONST);
    return new Number(execute());
}
