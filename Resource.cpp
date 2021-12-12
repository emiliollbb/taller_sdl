#include "Resource.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include "microtar.h"

using namespace std;

ResourceException::ResourceException(string& what) {
	cout << what << endl;
    this->message = what;
}

string* ResourceException::what(void) {
	return &message;
}

Resource::Resource(string &file_name) {
    this->file_name=file_name;
    this->data=NULL;
    this->size=0;
}

Resource::~Resource() {
    if(this->data!=NULL) {
        delete[] this->data;
        this->data=NULL;
    }
}

string Resource::getFileName(void) {
    return this->file_name;
}


void Resource::load_plain(void) {
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


void Resource::load(void) {
    // https://github.com/rxi/microtar
    mtar_t tar;
    mtar_header_t h;
    int status;
    
    /* Open tar archive for reading */
    status = mtar_open(&tar, "juego.dat", "r");    
    if(status!=0) {
        string error = "Error opening tar file "+ string(mtar_strerror(status));
        throw ResourceException(error);
    }
    
    /* Find file */
    status = mtar_find(&tar, this->file_name.c_str(), &h);
    if(status!=0) {
        string error = "Error locating resource in tar file "+ string(mtar_strerror(status));
        throw ResourceException(error);
    }
    
    /* Initialize data */
    this->size = h.size;
    this->data = new char[this->size];
    
    /* Read file */
    status = mtar_read_data(&tar, this->data, this->size);
    if(status!=0) {
        string error = "Error reading resource in tar file "+ string(mtar_strerror(status));
        throw ResourceException(error);
    }
    
    /* Close archive */
    status = mtar_close(&tar);
    if(status!=0) {
        string error = "Error closing tar file "+ string(mtar_strerror(status));
        throw ResourceException(error);
    }    
}


char* Resource::getData(void) {
    return this->data;
}

long Resource::getSize(void) {
    return this->size;
}
