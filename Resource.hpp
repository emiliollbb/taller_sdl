#include <string>

#ifndef RESOURCE_HPP
#define RESOURCE_HPP

using namespace std;

class ResourceException {
    private:
    protected:
        string message;
    public:
        ResourceException(string &what);
	string* what();
};

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
		void load_plain(void);
		void load(void);
		char* getData(void);
		long getSize(void);
};

#endif
