#include <iostream>
#include <string>
#include "Juego.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	try {
        cout <<"Hello!" << endl;

        Juego *juego = new Juego();
        juego->run();
            
        delete juego;
    } catch (JEngineException &e) {
		cout << "Error! " << *e.what() << endl;
        flush(cout);        
	}
    
    return 0;
}
