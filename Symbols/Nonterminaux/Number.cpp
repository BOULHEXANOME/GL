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

bool Number::analyse()
{
    setType(VAL);
    return true;
}

Expression* Number::optimizeExpression()
{
    this->setType(VAL);
    return this;
}

int Number::getType()
{
    return VAL;
}

void Number::resetType()
{
    symbolType = VAL;
}
