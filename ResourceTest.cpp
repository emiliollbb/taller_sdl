#include <iostream>
#include <string>
#include "Resource.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	try {
        cout <<"Resource test!" << endl;

        string resource_file = "background.png";
        Resource *resource = new Resource(resource_file);
        resource->load();
            
        delete resource;
    } catch (ResourceException &e) {
		cout << "ResourceException! " << e.what() << endl;
        flush(cout);        
	}
    
    return 0;
}
