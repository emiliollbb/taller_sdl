#include <string>

#ifndef RESOURCE_HPP
#define RESOURCE_HPP

using namespace std;

class Resource {
    private:
		string file_name;
		char *data;
		long size;
    protected:
    public:
		Resource(string &file_name);
		~Resource();
		string getFileName(void);
		void load(void);
		char* getData(void);
		long getSize(void);
};

#endif
