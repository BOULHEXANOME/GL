//
// Created by hdelval on 08/03/16.
//

#ifndef GL_MULTIPLYTERMINAL_H
#define GL_MULTIPLYTERMINAL_H


#include "../Symbol.h"

class MultiplyTerminal : public Symbol
{

public:
    MultiplyTerminal() { }
    virtual int getType() const;
};


#endif //GL_MULTIPLYTERMINAL_H
