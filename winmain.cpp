#include <iostream>
#include <string>
#include "Juego.hpp"
#include <windows.h>

using namespace std;

int main(int argc, char* argv[])
{
	try {
		Juego *juego = new Juego();
		juego->run();
		delete juego;
	} catch (JEngineException e) {
		MessageBox(
			NULL, e.what(), "Error!", MB_ICONWARNING | MB_OK
		);
	}
    
    return 0;
}
