#include "Resource.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

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

string Resource::getFileName(void) {
    return this->file_name;
}

void Resource::load(void) {
    cout << "load file" << endl;
    FILE *fp;
    
    fp = fopen ( "background.png" , "rb" );
    if(!fp) {
        exit(1);
    }

    fseek( fp , 0L , SEEK_END);
    this->size = ftell( fp );
    rewind( fp );

    /* allocate memory for entire content */
    this->data = (char*) calloc( 1, this->size+1 );
    if( !this->data ) fclose(fp),fputs("memory alloc fails",stderr),exit(1);

    /* copy the file into the buffer */
    if( 1!=fread(this->data , this->size, 1 , fp) )
      fclose(fp),free(this->data),fputs("entire read fails",stderr),exit(1);

    

    fclose(fp);
    cout << "loaded" << endl;
    
}

char* Resource::getData(void) {
    return this->data;
}

long Resource::getSize(void) {
    return this->size;
}
