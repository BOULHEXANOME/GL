//
// Created by hdelval on 08/03/16.
//

#include <sstream>
#include "Number.h"

std::string Number::print() const
{
    std::ostringstream convertToString;
    convertToString << theValue;
    return convertToString.str();
}
