//
// Created by hdelval on 08/03/16.
//

#include "Constant.h"

int Constant::execute() const
{
    try
    {
        return Automaton::instance().accessConstant(theName);
    }
    catch(const int e) {
        if(e == CONST_DOES_NOT_EXISTS)
        {
            Automaton::instance().printError(this);
        }
        else
        {
            std::cerr << "Erreur inconnue ";
            Automaton::instance().printError(this);
        }
    }
    return 0;
}

std::string Constant::print() const {
    return theName;
}

bool Constant::analyse() const
{
    return Automaton::instance().analyseAccessConstant(theName);
}
