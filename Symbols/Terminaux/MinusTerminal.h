//
// Created by hdelval on 08/03/16.
//

#ifndef GL_MINUSTERMINAL_H
#define GL_MINUSTERMINAL_H


#include "../Symbol.h"

class MinusTerminal : public Symbol
{

public:
    MinusTerminal() { }
    virtual int getType() const;
};


#endif //GL_MINUSTERMINAL_H
