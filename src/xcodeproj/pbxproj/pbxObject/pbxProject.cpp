//
//  pbxProject.cpp
//  Debug
//
//  Created by shichimi on 2017/03/25.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#include "pbxProject.hpp"
#include "pbxCreate.hpp"
#include "pbxWriter.hpp"
#include "pbxParser.h"

using namespace xcodeproj::pbxproj::pbxObject;

#define PBXPROJECT_FILE "project.pbxproj"

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            
            pbxProject::pbxProject(string xcodeproj){
                this->xcodeproj = xcodeproj;
                this->isOutPut = false;
            }
            
            void pbxProject::addPBXProject(std::string addFile){
                
                this->xcodeproj = this->xcodeproj + "/" + PBXPROJECT_FILE;

                pbxParser parser = pbxParser(this->xcodeproj.c_str());
                
                pbxCreate create = *new pbxCreate;
                
                parser.pbxprojParser();
                
                create.pbxObjectCreater(addFile);
                
                pbxWriter writer = pbxWriter(this->xcodeproj.c_str());
                writer.isOutPut = this->isOutPut;
                writer.mainUuid = parser.pbxMainGroup;
                writer.parentGroup = create.parentPath;
                writer.overwritePbx(create);
            }
        }
    }
}
