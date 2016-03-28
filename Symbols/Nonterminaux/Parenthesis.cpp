//
// Created by hdelval on 08/03/16.
//

#include "Parenthesis.h"
#include "Number.h"

std::string Parenthesis::print() const
{
    return "(" + exprParenthesised->print() + ")";
}

int Parenthesis::execute() const
{
    return exprParenthesised->execute();
}

bool Parenthesis::analyse()
{
    return exprParenthesised->analyse();
}

Expression *Parenthesis::optimizeExpression()
{
    setType(EXPR_PAR);
    exprParenthesised = exprParenthesised->optimizeExpression();
    if(exprParenthesised->getType() == VAL || exprParenthesised->getType() == CONST)
        return new Number(exprParenthesised->execute());
    if(exprParenthesised->getType() == VAR || exprParenthesised->getType() == EXPR_PAR)
        return exprParenthesised;
    return this;
}
