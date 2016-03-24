//
// Created by hdelval on 08/03/16.
//

#include "Parenthesis.h"

std::string Parenthesis::print() const
{
    return "(" + exprParenthesised->print() + ")";
}

int Parenthesis::execute() const
{
    return exprParenthesised->execute();
}

bool Parenthesis::analyse() const
{
    return exprParenthesised->analyse();
}

Expression *Parenthesis::optimizeExpression()
{
    exprParenthesised = exprParenthesised->optimizeExpression();
    return this;
}
