//
//  pbxCreate.hpp
//  PBXObject
//
//  Created by shichimi on 2017/01/31.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#ifndef pbxCreate_hpp
#define pbxCreate_hpp

#include <stdio.h>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            
            struct pbxChildren{
                string uuid;
                string filename;
            };
            class pbxCreate{
            public:
                
                vector<string> pbxGroups;
                vector<string> pbxReferencies;
                vector<string> pbxBuilds;
                vector<string> pbxFrameworks;
                vector<string> pbxResourcies;
                vector<string> pbxSourcies;
                vector<string> pbxContainer;

                string parentPath;
                string createPhase(string uuid, string file);
                static string fileEncoding(string file);
                static string fileType(string fileName);
                string fileExtention(string file);
                static string filelastKnownFileType(string file);
                string createUUID(string file_name);
                vector<string> pbxObjectCreater(string path);
                static string listOfChildren(vector<pbxChildren> children);
                pbxChildren pbxies(string uuid, string file);
                void filteringExtention(string path);
                string createPbxies(string uuid,string file);
                void debug(vector<string> debug);
            private:
                bool isSourceFile(string path);
                bool isBundleFile(string paht);
                bool isLibFile(string path);
                bool isHeaderFile(string path);
            };

            class pbxContainerItem {
            public:
                static string pbxContainerItemProxy(string uuid,string containerUuid, string projName, string remoteGlobalID);
            };

            class pbxBuildObject{
            public:
                static string pbxBuildCreater(string uuid, string fileName,string fileRef);
            };
            
            class pbxReferenceObject{
            public:
                static string pbxReferenceCreater(string uuid, string fileName);
            };
            
            class pbxGroupObject{
            public:
                static string pbxGroupCreater(string uuid,string parent, vector<pbxChildren> chilren);
            };
            
            class pbxBuildFramework{
            public:
                static string pbxBuildFrameworkCreater(vector<pbxChildren> files);
            };
            
            class pbxSourceBuildObject{
            public:
                static string pbxSourceBuildCreater(vector<pbxChildren> files);
            };
            
            class pbxResrouceBuildObject{
            public:
                static string pbxResourceBuildCreater(vector<pbxChildren> files);
            };
        }
    }
}
#endif /* pbxCreate_hpp */
