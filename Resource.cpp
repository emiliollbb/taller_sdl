#include "Resource.hpp"

using namespace std;

Resource::Resource(string &file_name) {
    this->file_name=file_name;
    this->data=NULL;
    this->size=0;
}

Resource::~Resource() {
    if(this->data!=NULL) {
        delete data;
        this->data=NULL;
    }
}
