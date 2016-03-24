//
// Created by hdelval on 08/03/16.
//

#include "Expression.h"

int Expression::execute() const
{
    std::cerr <<"Error, cannot execute Expression."<<std::endl;
	return 0;
}

Expression* Expression::optimizeExpression()
{
    return this;
}
