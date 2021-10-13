#include <iostream>
#include <string>
#include "JEngine.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	cout <<"Hello!" << endl;

    JEngine *engine = new JEngine();
    engine->init();
    engine->run();
    engine->close();
    
    delete engine;
}
