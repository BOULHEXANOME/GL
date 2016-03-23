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

Number::Number(int value)
{
	symbolType = VAL;
	theValue = value;
}

int Number::execute() const
{
    return theValue;
}

bool Number::analyse() const
{
    return true;
}

Expression* Number::optimizeExpression()
{
    return this;
}

int Number::getType()
{
    return VAL;
}
