#include "option.h"

option::option(){
	this->option_s.output = "";
	this->option_s.overwrite = "";
	this->option_s.version = "";
	this->option_s.addFile = "";
}

void option::setOption(int argc, const char *argv[]){

	int i = 0;
    
	for(; i<argc; i++){
		if(strcmp(argv[i], "-o")==0){
            this->option_s.output = OPTION_OUTPUT;
        }else if(strcmp(argv[i], "-w")==0){
        	this->option_s.overwrite = OPTION_OVERWIRTE;
        }else if(strcmp(argv[i], "-v")==0){
        	this->option_s.version = OPTION_VERSION;
        }else if(strcmp(argv[i], "-a")==0){
        	this->option_s.addFile = argv[i+1];
        }
    }
}