//
// Created by hdelval on 04/03/16.
//

#include "Read.h"

std::string Read::print() const
{
    return "lire " + variableToReadFromUser->print();
}

int Read::execute() const
{
    int numberFromUser;
    std::cout << variableToReadFromUser->getTheName() << " = ?" << std::endl;
    std::cin >> numberFromUser;
    if(! Automaton::instance().affectVariable(this->variableToReadFromUser->getTheName(), numberFromUser))
    {
        // TODO
        std::cerr << "error declare ! print line number&column" << std::endl;
    }
    return 0;
}

bool Read::analyse() const
{
    if(! Automaton::instance().analyseAffectVariable(this->variableToReadFromUser->getTheName()))
    {
        // TODO
        std::cerr << "error declare ! print line number&column" << std::endl;
        return false;
    }
    return true;
}
