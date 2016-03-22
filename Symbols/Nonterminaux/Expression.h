//
// Created by hdelval on 08/03/16.
//

#ifndef GL_EXPRESSION_H
#define GL_EXPRESSION_H


#include "../Symbol.h"

class Expression : public Symbol
{
public:
		virtual int execute() const;
};


#endif //GL_EXPRESSION_H
