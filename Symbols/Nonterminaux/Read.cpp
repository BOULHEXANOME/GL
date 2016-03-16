//
// Created by hdelval on 04/03/16.
//

#include "Read.h"

std::string ReadTerminal::print() const
{
    return "lire " + variableToReadFromUser->print();
}
