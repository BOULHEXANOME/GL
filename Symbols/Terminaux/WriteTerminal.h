//
// Created by hdelval on 08/03/16.
//

#ifndef GL_WRITETERMINAL_H
#define GL_WRITETERMINAL_H


#include "../Symbol.h"

class WriteTerminal : public Symbol {

public:
    WriteTerminal() { }
    virtual int getType();
};


#endif //GL_WRITETERMINAL_H
