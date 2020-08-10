//
// Created by shichimi on 2017/01/23.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#ifndef PBXOBJECT_PBXPARSER_H
#define PBXOBJECT_PBXPARSER_H

#include <string>
#include <vector>
#include <cstring>

using namespace std;

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject{
            class pbxParser {
            public:
                pbxParser(const char* path);
                const char* parserPath;
                void pbxprojParser();
                void pbxprojOverWriteParser(const string path);
                vector<string> pbxBuilds;
                vector<string> pbxReferencies;
                string pbxMainGroup;
            private:
                std::string emurate(std::string buffer);
            };
        }
    }
}
#endif /*PBXOBJECT_PBXPARSER_H*/
