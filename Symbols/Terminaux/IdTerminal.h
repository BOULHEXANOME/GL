//
// Created by hdelval on 09/03/16.
//

#ifndef GL_IDTERMINAL_H
#define GL_IDTERMINAL_H


#include "../Symbol.h"
#include <string>

class IdTerminal : public Symbol{
private:
    std::string theName;
public:

    IdTerminal(const std::string & theName) : theName(theName) { }

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    const std::string & getTheName() const
    {
        return theName;
    }

    void setTheName(const std::string & theName)
    {
        IdTerminal::theName = theName;
    }
    /***********************/
    /* End Getters/Setters */
    /***********************/

    virtual int getType();
};

#endif //GL_IDTERMINAL_H
