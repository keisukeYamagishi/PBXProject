//
//  pbxWriter.hpp
//  PBXObject
//
//  Created by shichimi on 2017/02/08.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#ifndef pbxWriter_hpp
#define pbxWriter_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "pbxCreate.hpp"
#include <cstring>

using namespace std;

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            class pbxWriter{
            public:
                
                bool isOutPut;
                pbxWriter(const char* path);
                void overwritePbx(pbxObject::pbxCreate pbx);
                string mainUuid;
                string parentGroup;
                
            private:
                bool isVariant;
                bool isSource;
                bool isResource;
                bool isFramework;
                bool isPbxGroup;
                bool isMainGroup;
                const char* writerPath;
                string createBuildSection(vector<string>);
                string CreateBuildPhase(vector<string>);
                string createOverwriteValue(vector<string> values);
            };
        }
    }
}

#endif /* pbxWriter_hpp */
