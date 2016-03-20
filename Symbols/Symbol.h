//
// Created by hdelval on 04/03/16.
//

#ifndef GL_SYMBOL_H
#define GL_SYMBOL_H

#include "../symbolTypes.h"
#include "../Automaton.h"
#include <iostream>
class Automaton;

class Symbol
{
protected:
    int columnWhereSymbolOccurs = -1;
    int lineWhereSymbolOccurs = -1;

public:

    /***********************/
    /*** Getters/Setters ***/
    /***********************/
    int getColumnWhereSymbolOccurs() const
    {
        return columnWhereSymbolOccurs;
    }

    void setColumnWhereSymbolOccurs(int columnWhereSymbolOccurs)
    {
        Symbol::columnWhereSymbolOccurs = columnWhereSymbolOccurs;
    }

    int getLineWhereSymbolOccurs() const
    {
        return lineWhereSymbolOccurs;
    }

    void setLineWhereSymbolOccurs(int lineWhereSymbolOccurs)
    {
        Symbol::lineWhereSymbolOccurs = lineWhereSymbolOccurs;
    }

    /***********************/
    /* End Getters/Setters */
    /***********************/

    /************************/
    /** Override operators **/
    /************************/
    friend std::ostream & operator<<(std::ostream& os, const Symbol & s);
    /************************/
    /*End Override operators /
    /************************/

    /***********************/
    /******* Methods *******/
    /***********************/

    /*
     * Execute symbol
     */
    virtual int execute() const;

    virtual int getType() const;
    virtual std::string print() const;
    /***********************/
    /***** End Methods *****/
    /***********************/
};


#endif //GL_SYMBOL_H
