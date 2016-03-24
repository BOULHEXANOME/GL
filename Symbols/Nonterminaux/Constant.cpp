//
// Created by hdelval on 08/03/16.
//

#include "Constant.h"
#include "Number.h"

int Constant::execute() const
{
    try
    {
        return Automaton::instance().accessConstant(theName);
    }
    catch(const int e) {
        if(e == CONST_DOES_NOT_EXISTS)
        {
            // TODO
            std::cerr << "error accessing const ! print line number&column" << std::endl;
        }
        else
        {
            std::cerr << "unknown error ! print line number&column" << std::endl;
        }
    }
    return 0;
}

std::string Constant::print() const {
    return theName;
}

bool Constant::analyse() const {
    return true;
}

int Constant::getType()
{
    return CONST;
}

Expression *Constant::optimizeExpression()
{
    return new Number(execute());
}
