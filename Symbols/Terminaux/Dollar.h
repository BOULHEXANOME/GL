//
// Created by hdelval on 09/03/16.
//

#ifndef GL_DOLLAR_H
#define GL_DOLLAR_H


#include "../Symbol.h"

class Dollar : public Symbol
{

public:
    Dollar() { }
    virtual int getType() const;
};


#endif //GL_DOLLAR_H
