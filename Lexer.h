#ifndef LEXER_H
#define LEXER_H

#include <string>

using namespace std;

class Lexer
{
    public:
        Lexer();
        Lexer(std::string nom_fic);
        *Symbol getSymbol();
        virtual ~Lexer();
    protected:
    private:
        string nom_fic;
};

#endif // LEXER_H
