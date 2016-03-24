#include <iostream>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include "Automaton.h"
#include "Lexer.h"
#include "Symbols/Symbol.h"

#define MIN_ARGS 2
#define MAX_ARGS 5

#define ERROR_NOT_ENOUGH_ARGS 1
#define ERROR_TOO_MANY_ARGS 1
#define ERROR_BAD_INPUT 1
#define ERROR_INCORRECT_PROGRAM 1

void defaultBehaviour();

using namespace std;

void print_usage()
{
    cerr << "  Utilisation :" << std::endl;
    cerr << "    ../lut [-p] [-a] [-e] [-o] source.lt" << endl;
    cerr << "      [-p] affiche le code source reconnu" << endl;
    cerr << "      [-a] analyse le programme de maniere statique" << endl;
    cerr << "      [-e] execute interactivement le programme" << endl;
    cerr << "      [-o] optimise les expressions et instructions" << endl;
}

inline bool file_exists (const string& name) {
	
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv) {
    
    bool opt_print = false;
    bool opt_analyse = false;
	bool opt_execute = false; 
	bool opt_optimize = false;
	string file_path;

    if (argc < MIN_ARGS)
    {
        if(Automaton::instance().isDebug())
        {
            defaultBehaviour();
            return 0;
        }
        else
        {
            cerr << "Erreur, veuillez specifier des arguments" << endl;
		    print_usage();
            exit(ERROR_NOT_ENOUGH_ARGS);
        }
    }

	if (argc > MAX_ARGS)
    {
		print_usage();
		exit(ERROR_TOO_MANY_ARGS);
	}
	
	// Filepath est le dernier argument
	file_path = argv[argc-1];
    
    int opt;
    
    while ((opt = getopt(argc,argv,"paeo")) != EOF)
    {
        switch(opt)
        {
            case 'p': 
				opt_print = true;
				break;
            
            case 'a':
				opt_analyse = true;
				break;
            
            case 'e':
				opt_execute = true;
				break;
            
            case 'o':
				opt_optimize = true;
				break;
            
            case '?': print_usage();
				exit(ERROR_BAD_INPUT);
				break;
            
            default : 
				break;
        }
	}
  
	if(!file_exists(file_path))
    {
		cerr << "Erreur a l'ouverture du fichier " << file_path << endl;
		exit(ERROR_BAD_INPUT);
	} else {
		
		// Instancition du Lexer -> A changer de place possiblement
		Lexer lexer(file_path);
		
		// Donne le Texte du fichier source à l'automate
		Automaton::instance().setStringsOfTheFile( lexer.getStringVector() );
		
		Symbol* symbol;

		// Parcourt le fichier et ajoute les symboles à la pile
		do {
			// Recupère le symbole suivant auprès du Lexer
			symbol = lexer.getSymbol();

			// Ajouter le symbole à la pile des symboles
			
			Automaton::instance().pushSymbol(symbol);

			//Automaton::instance().printError(symbol);

		} while(symbol->getType() != DOLLAR);
	}

	Automaton::instance().launchProgramFromLexer();

	if(opt_analyse)
    {
        Automaton::instance().analyse();
	}

	if(opt_optimize)
    {
        Automaton::instance().optimize();
	}

	if(opt_print)
    {
        Automaton::instance().printCode();
	}

	if(opt_execute)
    {
        Automaton::instance().execute();
	}

    return 0;
}

void defaultBehaviour()
{
    Automaton::instance().testStates6();
    //Automaton::instance().analyse();
    Automaton::instance().execute();
    Automaton::instance().printCode();
    Automaton::instance().optimize();
    Automaton::instance().execute();
    Automaton::instance().printCode();

}

