//
//  pbxWriter.cpp
//  PBXObject
//
//  Created by shichimi on 2017/02/08.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#include "pbxWriter.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include "pbxObjectSection.h"
#include "Util.h"

#define PBX_FILES_STRING "files = ("
#define PBX_CHILDREN_STRING "children = ("

using namespace xcodeproj::pbxproj::pbxObject;

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            
            pbxWriter::pbxWriter(const char* path){
                this->isSource = false;
                this->isResource = false;
                this->isFramework = false;
                this->isPbxGroup = false;
                this->isMainGroup = false;
                this->isOutPut = false;
                this->writerPath = path;
            }
            
            void pbxWriter::overwritePbx(pbxObject::pbxCreate pbx){
                
                fstream fst(this->writerPath);
                
                string buf;
                string pbxproj;
                string split;
                bool isBuild = false;
                
                while(fst && getline(fst, buf)) {
                    
                    if(BeginPBXContainerItemProxy==buf 
                        || isBuild == true){
                        isBuild = false;
                        buf = "\n" + createOverwriteValue(pbx.pbxContainer) + buf;
                    }

                    if(EndPBXBuildFileSection==buf){
                        isBuild = true;
                        buf = createOverwriteValue(pbx.pbxBuilds) + buf;
                    }

                    if(EndPBXFileReferenceSection==buf)
                        buf = createOverwriteValue(pbx.pbxReferencies) + buf;
                    
                    if(BeginPBXGroupSection==buf
                       || this->isPbxGroup==true){
                        
                        this->isPbxGroup = true;
                        
                        string uuid = Util::emurateString(buf, {"\t"," ", "=", "{","\n"});
                        
                        if(uuid == this->mainUuid
                           || this->isMainGroup == true){
                            
                            this->isMainGroup = true;
                            
                            if(buf.find(PBX_CHILDREN_STRING)!=string::npos){
                                this->isMainGroup = false;
                                buf = buf + "\n" + this->parentGroup;
                            }
                        }
                        if(EndPBXGroupSection==buf){
                            this->isPbxGroup = false;
                            buf = createOverwriteValue(pbx.pbxGroups) + buf;
                        }
                    }
                    
                    if(BeginPBXSourcesBuildPhaseSection==buf
                       || this->isSource == true){
                        
                        this->isSource = true;
                        
                        if(buf.find(PBX_FILES_STRING) != string::npos){
                            this->isSource = false;
                            buf = buf + "\n" +  createBuildSection(pbx.pbxSourcies);
                        }
                    }
                    
                    if(BeginPBXResourcesBuildPhaseSection==buf
                       || this->isResource == true){
                        
                        this->isResource = true;
                        
                        if(buf.find(PBX_FILES_STRING) != string::npos){
                            this->isResource = false;
                            buf = buf + "\n" + createBuildSection(pbx.pbxResourcies);
                        }
                    }
                    
                    if(BeginPBXFrameworksBuildPhaseSection==buf
                       || this->isFramework == true){
                        
                        this->isFramework = true;
                        
                        if(buf.find(PBX_FILES_STRING) != string::npos){
                            this->isFramework = false;
                            buf = buf + "\n" + createBuildSection(pbx.pbxFrameworks);
                        }
                    }
                    pbxproj = pbxproj + buf + "\n";
                }
                if(this->isOutPut==true)
                    cout << pbxproj << endl;
                
                ofstream outputfile(this->writerPath);
                outputfile<<pbxproj;
                outputfile.close();
            }
            
            string pbxWriter::createBuildSection(vector<string> values){
                
                string overwirte;
                for(auto itr = values.begin(); itr != values.end(); ++itr)
                    overwirte += *itr;
                
                return overwirte;
            }
            
            string pbxWriter::createOverwriteValue(vector<string> values){
                string overwirte;
                for(auto itr = values.begin(); itr != values.end(); ++itr)
                    overwirte += *itr + "\n";
                return overwirte;
            }
        }
    }
}
