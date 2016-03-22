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

void print_usage() {
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
        defaultBehaviour();
        return 0;
//		print_usage();
	//	exit(ERROR_NOT_ENOUGH_ARGS);
		
	}
    
	if (argc > MAX_ARGS)
    {
		print_usage();
		exit(ERROR_TOO_MANY_ARGS);
	}
	
	// Filepath est le dernier argument
	file_path = argv[argc-1];
    
    int opt,a,b,c;
    
    while ((opt = getopt(argc,argv,"paeo")) != EOF)
    {
        switch(opt)
        {
            case 'p': 
				cout << "Affichage du programme" << endl;
				opt_print = true;
				break;
            
            case 'a':
				cout << "Analyse statique du programme" << endl; 
				opt_analyse = true;
				break;
				
            
            case 'e':
				cout << "Execution du programme" << endl ; 
				opt_execute = true;
				break;
            
            case 'o':
				cout << "Simplification du programme " << endl ; 
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
		//lexer.getStringVector();
		
		Symbol* symbol;
		int i = 0;

		// Parcourt le fichier et ajoute les symboles à la pile
		do {
			// Recupère le symbole suivant auprès du Lexer
			symbol = lexer.getSymbol();
			
			//std::cout << "Symbole à pusher : " << symbol->getType() << std::endl;
			//std::cout << "Ligne : " << symbol->getLineWhereSymbolOccurs() << std::endl;
			//std::cout << "Colonne : " << symbol->getColumnWhereSymbolOccurs() << std::endl;
			
			// Ajouter le symbole à la pile des symboles
			Automaton::instance().pushSymbol(symbol);
						
		} while(symbol->getType() != DOLLAR);
		
		
	}

	if(opt_analyse)
    {

	}

	if(opt_optimize)
    {

	}

	if(opt_print)
    {
        Automaton::instance().printCode();
	}

	if(opt_execute)
    {

	}

    return 0;
}

void defaultBehaviour()
{
//    Automaton::instance().createSomeLines();
//    Automaton::instance().printCode();
//    Automaton::instance().testStates();
//    Automaton::instance().testStates4();
//    Automaton::instance().testStates5();
  //  Automaton::instance().testStates4();
    //Automaton::instance().testLire();
    Automaton::instance().testConst();
    Automaton::instance().execute();

}

