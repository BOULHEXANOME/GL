//
// Created by hdelval on 08/03/16.
//

#ifndef GL_DIVIDETERMINAL_H
#define GL_DIVIDETERMINAL_H


#include "../Symbol.h"

class DivideTerminal : public Symbol
{

public:
    DivideTerminal() { }
    virtual int getType() const;
};


#endif //GL_DIVIDETERMINAL_H
