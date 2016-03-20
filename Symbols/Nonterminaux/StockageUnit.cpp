//
// Created by hdelval on 08/03/16.
//

#include "StockageUnit.h"
#include "../../exceptions.h"

std::string StockageUnit::print() const
{
    return theName;
}

int StockageUnit::execute() const
{
    var* theStockageUnit = new var;
    if(Automaton::instance().accessVariable(theName, theStockageUnit))
    {
        return theStockageUnit->theValue;
    }
    else
    {
        try
        {
            return Automaton::instance().accessConstant(theName);
        }
        catch(const int e) {
            if(e == CONST_DOES_NOT_EXISTS)
            {
                // TODO
                std::cerr << "error accessing const/var ! print line number&column" << std::endl;
            }
            else
            {
                std::cerr << "unknown error ! print line number&column" << std::endl;
            }
        }
    }

}
