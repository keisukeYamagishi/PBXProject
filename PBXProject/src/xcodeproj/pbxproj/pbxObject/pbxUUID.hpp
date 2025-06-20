//
//  pbxUUID.hpp
//  PBXObject
//
//  Created by shichimi on 2017/01/31.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#ifndef pbxUUID_hpp
#define pbxUUID_hpp

#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            class pbxUUID{
            public:
                static pbxUUID* getInstance();
                vector<string> uuidStore;
                map<string, string> uuidModel;
                string pbx_uuid_generater(string uuid);
                string pbx_uuid_string(int index);
                string pbxGenerater(string path);
            private:
                bool containObject(vector<string> uuids, string contain);
                string pbx_uuid_string();
            };
        }
    }
}
#endif /* pbxUUID_hpp */
