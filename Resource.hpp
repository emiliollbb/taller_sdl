#include <string>

#ifndef RESOURCE_HPP
#define RESOURCE_HPP

using namespace std;

class Resource {
    private:
		string file_name;
		unsigned char *data;
		unsigned long size;
    protected:
    public:
		Resource(string &file_name);
		~Resource();
};

#endif
