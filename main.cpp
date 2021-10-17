#include <iostream>
#include <string>
#include "Juego.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	cout <<"Hello!" << endl;

    Juego *juego = new Juego();
    juego->run();
        
    delete juego;
    
    return 0;
}
