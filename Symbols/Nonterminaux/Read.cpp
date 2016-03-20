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
    std::cout << variableToReadFromUser->getTheName() << " = ?";
    std::cin >> numberFromUser;
    if(! Automaton::instance().affectVariable(this->variableToReadFromUser->getTheName(), numberFromUser))
    {
        // TODO
        std::cerr << "error declare ! print line number&column" << std::endl;
    }
    return 0;
}
