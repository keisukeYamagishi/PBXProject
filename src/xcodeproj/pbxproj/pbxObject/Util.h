//
//  detect.h
//  detect
//
//  Created by keisukeYamagishi on 2017/01/29.
//  Copyright © 2017年 keisukeYamagishi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#ifndef Util_h
#define Util_h

#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <list>

using namespace std;
namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            class Util{
            public:
                //Detect file
                static string emurateString(string base, vector<string> removes);
                
                /*******************************************************
                 *
                 * detect the pbxproj file.
                 * pram: search path string
                 *       search string
                 * used to detect the pbxproj file,
                 * store it in an array and return it.
                 *
                 *******************************************************
                 */
                static vector<string> detectFile(string path, string search);
                
                /*******************************************************
                 * Returns the extension of a string.
                 * param: file path
                 *
                 *******************************************************
                 */
                static string extension(const string &path);
                
                /*******************************************************
                 * Returs the last path components
                 * param: file name
                 * use only file
                 *
                 *******************************************************
                 */
                static string lastPath (const std::string &str);
                
                /*******************************************************
                 * Split character string with specific character string
                 * param: String to be split
                 *
                 *******************************************************
                 */
                static std::vector<std::string> split(const std::string &str, char sep);
                
                /*******************************************************
                 * remove character string with specific character string
                 * param: String to be remove
                 *
                 *******************************************************
                 */
                static std::string removeCharacter(std::string str, std::string remove);
                
                /*******************************************************
                 * Returns the character string from which 
                 * the specified character string is deleted.
                 * param: String to be emurate
                 *        remove list
                 *
                 *******************************************************
                 */
                static std::string emurateCharactor(std::string str, list<string> lists);
                
                /*******************************************************
                 * List all the files and directories stored in the directory.
                 * param: file path
                 *
                 *******************************************************
                 */
                static vector<string> listDirectory(const char* path);
                
                /*******************************************************
                 * Judgment file or directory
                 * param: fule path
                 *
                 *******************************************************
                 */
                static bool isDirectory(const char* path);
                
                /*******************************************************
                 * remove stirng
                 * param: String to be remove and file path
                 *
                 *******************************************************
                 */
                static string removeString(string base, string remove);
                
                /*******************************************************
                 * Returns file extention
                 * param: file path
                 *
                 *******************************************************
                 */
                static string pathExtention(const string &path);

                static string removeExtention(string fileName);

                static string escapeCode(string file);
            };
        }
    }
}
#endif
