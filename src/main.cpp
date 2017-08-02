//
//  main.cpp
//  PBXObject
//
//  Created by shichimi on 2017/01/23.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#include <iostream>
#include <string>
#include "pbxProject.hpp"
#include "option.h"

using namespace xcodeproj::pbxproj::pbxObject;
using namespace std;

#define PBXPROJECT_VERSION "1.0.4"

int main(int argc, const char * argv[]) {

    option op = option();
    op.setOption(argc,argv);

    if(argv[1]==NULL){
        cout << "usage: PBXProject [-v] [<path>] [-a addFile=value] [-o output]" << endl;
        cout << "\n";
        cout << "These are common PBXProject commands used in various situations:" << endl;
        cout << "\n";
        cout << "PBXProject version: " << PBXPROJECT_VERSION << endl;
        cout << "\n";
        cout << "(*_*).oO Hi How to use option see the bellow " << endl;
        cout << "\n";
        cout << "***************************************************" << endl;
        cout << "\n";
        cout << "-v:  display PBXProject version number" << endl;
        cout << "-o:  output result" << endl;
        cout << "-a:  add File or directory" << endl; 
        cout << "\n";
        cout << "***************************************************" << endl;
        cout << "\n";
        cout << "Regars !" << endl;
        cout << "\n";
    }else if(op.option_s.version == OPTION_VERSION){

        cout << "PBXProject version: " << PBXPROJECT_VERSION << endl;

    }else if(op.option_s.addFile.size() != 0){
        /*
         * Specify the path of the xcodeproj file you want to add.
         *
         */
        string path = string(argv[1]);
    
        /*
         * Specify the file path to add
         *
         */
        string add_path = op.option_s.addFile;
    
        pbxProject pbxproj = pbxProject(path);
        if(op.option_s.output==OPTION_OUTPUT)
            pbxproj.isOutPut = true;
        pbxproj.addPBXProject(add_path);
    }
    
    return 0;
}
