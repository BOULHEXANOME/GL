//
// Created by hdelval on 08/03/16.
//

#include "Variable.h"

int Variable::execute() const
{
    var* theStockageUnit = new var;
    if(! Automaton::instance().accessVariable(theName, theStockageUnit))
    {
        // TODO
        std::cerr << "error execute variable ! print line number&column" << std::endl;
    }
    return theStockageUnit->theValue;
}

bool Variable::analyse() const
{
    if(! Automaton::instance().analyseAccessVariable(theName))
    {
        // TODO
        std::cerr << "error execute variable ! print line number&column" << std::endl;
        return false;
    }
    return true;
}
