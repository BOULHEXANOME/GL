//
// Created by hdelval on 08/03/16.
//

#ifndef GL_VARTERMINAL_H
#define GL_VARTERMINAL_H


#include "../Symbol.h"

class VarTerminal : public Symbol
{
public:

    VarTerminal() { }
    virtual int getType() const;
};


#endif //GL_VARTERMINAL_H
