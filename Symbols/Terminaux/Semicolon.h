//
// Created by hdelval on 09/03/16.
//

#ifndef GL_SEMICOLON_H
#define GL_SEMICOLON_H


#include "../Symbol.h"

class Semicolon : public Symbol
{

public:
    Semicolon() { }
    virtual int getType() const;
};


#endif //GL_SEMICOLON_H
