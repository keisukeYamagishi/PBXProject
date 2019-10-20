//
//  detect.cpp
//  detect
//
//  Created by keisukeYamagishi on 2017/01/29.
//  Copyright © 2017年 keisukeYamagishi. All rights reserved.
//

#include "Util.h"
#include <iostream>
#include <sstream>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {

            vector<string> Util::listDirectory(const char *path){
                vector<string> dir;
                DIR* dp=opendir(path);
                if (dp!=NULL)
                {
                    struct dirent* dent;
                    do{
                        dent = readdir(dp);
                        if (dent!=NULL){
                            string fullPath = "";
                            string path_str = string(path);
                            fullPath  = string(path) + "/";
                            fullPath += string(dent->d_name);
                            
                            if(lastPath(fullPath)!="."
                               && lastPath(fullPath)!=".."){
                                dir.push_back(fullPath);
                            }
                        }
                    }while(dent!=NULL);
                    closedir(dp);
                }
                return dir;
            }
            
            bool Util::isDirectory(const char *path){
                struct stat stat_buf;
                
                stat(path, &stat_buf);
                if ((stat_buf.st_mode & S_IFMT) == S_IFDIR
                    && strcmp(lastPath(string(path)).c_str(), ".")
                    && strcmp(lastPath(string(path)).c_str(), "..")) {
                    return true;
                }
                return false;
            }
            
            string Util::pathExtention(const string &path){
                
                vector<string> splits = Util::split(path, '/');
                if(!isDirectory(path.c_str())){
                    return extension(splits[splits.size()-1]);
                }
                return "";
            }
            
            string Util::extension(const string &path) {
                string ext;
                size_t pos1 = path.rfind('.');
                if(pos1 != string::npos)
                    ext = path.substr(pos1+1, path.size()-pos1);
                return ext;
            }
            
            string Util::lastPath(const std::string &str){
                
                vector<string> strs = Util::split(str, '/');
                
                return strs[strs.size()-1];
            }
            
            string Util::emurateString(string base, vector<string> removes){
                
                string emurate = base;
                
                for(auto itr = removes.begin(); itr != removes.end(); ++itr){
                    
                    string remove = *itr;
                    
                    emurate = Util::removeString(emurate, remove);
                    
                }
                return emurate;
                
            }
            
            string Util::removeString(string base, string remove){
                
                for(size_t location = base.find_first_of(remove); location != string::npos; location = base.find_first_of(remove)){
                    base.erase(location,1);
                }
                return base;
            }

            string Util::removeExtention(string fileName){
                std::vector<string> file = Util::split(fileName, '.');
                if(file[0]!="")
                    return file[0];
                return "";
            }

            std::vector<std::string> Util::split(const std::string &str, char sep)
            {
                std::vector<std::string> splits;
                std::stringstream string_str(str);
                std::string buffer;
                while( std::getline(string_str, buffer, sep) ) {
                    if(buffer!=""){
                        splits.push_back(buffer);
                    }
                }
                return splits;
            }

            string Util::escapeCode(string file){
                if(file.find("-") != string::npos
                    || file.find(" ") != string::npos
                    || file.find("+") != string::npos)
                    return "\"" + file + "\"";
                
                return file;
            }

            string replaceCharacter(string base, string replace){
                string str(base);
                str.replace(0,base.size(), replace);
                return str;
            }
        }
    }
}
