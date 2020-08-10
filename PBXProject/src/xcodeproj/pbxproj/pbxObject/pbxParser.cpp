//
// Created by shichimi on 2017/01/23.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//

#include "pbxParser.h"
#include "pbxObjectSection.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "pbxUUID.hpp"
#include "Util.h"

#define PBX_MAINGROUP "mainGroup"

bool isPbxBuild;
bool isPbxReference;
bool isPbxProject;

using namespace xcodeproj::pbxproj::pbxObject;

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject{
            
            pbxParser::pbxParser(const char* path){
                isPbxBuild = false;
                isPbxReference = false;
                isPbxProject = false;
                this->parserPath = path;
            }
            
            void pbxParser::pbxprojParser(){
                
                fstream fst(this->parserPath);
                
                string buf;
                
                while(fst && getline(fst, buf)) {
                    
                    if(buf==BeginPBXBuildFileSection
                       || isPbxBuild == true){
                        
                        isPbxBuild = true;
                        pbxUUID::getInstance()->uuidStore.push_back(pbxParser::emurate(buf));
                        
                        if(buf==EndPBXBuildFileSection) isPbxBuild = false;
                        
                    }
                    
                    if(buf==BeginPBXFileReferenceSection
                       || isPbxReference==true){
                        
                        isPbxReference=true;
                        
                        pbxUUID::getInstance()->uuidStore.push_back(pbxParser::emurate(buf));
                        
                        if(buf==EndPBXFileReferenceSection) isPbxReference=false;
                    }
                    
                    if(BeginPBXProjectSection==buf
                       || isPbxProject == true){
                        
                        isPbxProject = true;
                        
                        if(buf.find(PBX_MAINGROUP)!=string::npos){
                            
                            vector<string> splitStr = Util::split(buf, '=');
                            
                            string mainUuid = Util::emurateString(splitStr[1], {";"," "});
                            
                            pbxMainGroup = mainUuid;
                        }
                    }
                }
            }
            
            string pbxParser::emurate(std::string buffer){
                
                stringstream ss(buffer);
                string splitPbx;
                string emurateStr;
                int count = 0;
                bool isFilename = false;
                
                while (getline(ss, splitPbx, ' ')) {
                    
                    if(count==0)
                        emurateStr = splitPbx;
                    
                    if(isFilename==true)
                        isFilename = false;
                    
                    if(splitPbx=="/*")
                        isFilename = true;
                    
                    count++;
                }
                return emurateStr;
            }
        }
    }
}
