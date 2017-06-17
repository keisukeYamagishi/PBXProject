//
//  pbxProject.hpp
//  Debug
//
//  Created by shichimi on 2017/03/25.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#ifndef pbxProject_hpp
#define pbxProject_hpp

#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

/*****************************
 * pbxproj control class
 *
 * Class to edit xcodeproj.
 * Mainly add files
 *
 */
namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            class pbxProject{
            public:
                bool isOutPut;
                /**************************************
                 *
                 * Path of xcodeproj file
                 * Please set a value for this member variable.
                 ****************************************
                 */
                string xcodeproj;
                
                /***************************************
                 *
                 * path of add folder or file
                 * Please set a value for this member variable.
                 *
                 **************************************
                 */
                string addPath;
                
                /**************************************
                 * Constructor
                 * @parame
                 * set xcodeproj file path
                 *
                 **************************************
                 */
                pbxProject(string xcodeproj);
                
                /***************************************
                 * Member function to let xcode detect files
                 * @parame
                 * pbxproj Pass the path of the. pbxproj file.
                 * add:    Pass in the path of the file you want to add.
                 *
                 *
                 *****************************************/
                void addPBXProject(string addFile);
            };
        }
    }
}
#endif /* pbxProject_hpp */
