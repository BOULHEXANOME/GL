//
// Created by hdelval on 08/03/16.
//

#ifndef GL_AFFECTDECLARETERMINAL_H
#define GL_AFFECTDECLARETERMINAL_H


#include "../Symbol.h"

class AffectDeclareTerminal : public Symbol
{

public:
    AffectDeclareTerminal() { }
    virtual int getType();
};


#endif //GL_AFFECTDECLARETERMINAL_H
