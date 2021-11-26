#include "Resource.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <zip.h>

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
        delete data;
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
    // https://gist.github.com/mobius/1759816
    struct zip *za;
    int zlib_error;
    
    za = zip_open("juego.dat", 0, &zlib_error);
    if(za == NULL) {
        string error = "Error opening zip file";
        throw ResourceException(error);
    }
    
    int zip_entries_count=zip_get_num_entries(za, 0);
    for (int i = 0; i <zip_entries_count; i++) {
        struct zip_stat sb;
        int status = zip_stat_index(za, i, 0, &sb);
        if(status!=0) {
            string error="Error stat entry";
            throw ResourceException(error);
        }
        string zip_entry_name = string(sb.name);
        if(zip_entry_name==this->file_name) {
            this->size = sb.size;
                        
            struct zip_file *zf = zip_fopen_index(za, i, 0);
            if (!zf) {
                string error="Error fopen entry";
                throw ResourceException(error);
            }
            
            this->data = (char*) malloc(this->size*sizeof(char));
            int len = zip_fread(zf, this->data, this->size);
            if (len < 0) {
                string error="Error reading entry";
                throw ResourceException(error);
            }
                        
            if (zip_fclose(zf) == -1) {
                string error = "Error closing zip entry";
                throw ResourceException(error);
            }
        }
    }
        
    
    if (zip_close(za) == -1) {
        string error = "Error closing zip file";
        throw ResourceException(error);
    }
}


char* Resource::getData(void) {
    return this->data;
}

long Resource::getSize(void) {
    return this->size;
}
