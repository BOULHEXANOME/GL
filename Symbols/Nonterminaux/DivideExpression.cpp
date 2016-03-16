//
// Created by hdelval on 08/03/16.
//

#include "DivideExpression.h"

std::string DivideExpression::print() const
{
    return leftExpr->print() + " / " + rigthExpr->print();
}

Symbol DivideExpression::optimize() {
	int typeLeft = leftExpr->getType();
	if(typeLeft = NON_TERMINAL)
	{
		newLeftExpr = leftExpr->optimize();
	}
	
	int typeRight = leftExpr->getType();
	if(typeRight = NON_TERMINAL)
	{
		newRightExpr = rightExpr->optimize();
	}	
}
