//
//  pbxUUID.cpp
//  PBXObject
//
//  Created by shichimi on 2017/01/31.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#include "pbxUUID.hpp"
#include <iostream>
#include <random>
#include <sstream>
#include <iomanip>


using namespace xcodeproj::pbxproj::pbxObject;

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {
            pbxUUID* pbxInstance = nullptr;
            
            pbxUUID* pbxUUID::getInstance(){
                
                if(pbxInstance==nullptr)
                    pbxInstance = new pbxUUID;
                
                return pbxInstance;
            }
            
            string pbxUUID::pbxGenerater(string path){
                
                string uuid = "";
                
                uuid = pbxUUID::getInstance()->uuidModel[path];
                
                if(uuid==""){
                    
                    uuid = pbx_uuid_generater("");
                    
                    pbxUUID::getInstance()->uuidModel[path] = uuid;
                    
                }
                return uuid;
            }
            
            string pbxUUID::pbx_uuid_generater(string uuid){
                return pbx_uuid_string();
            }

            string pbxUUID::pbx_uuid_string() {
                random_device rd;
                mt19937_64 gen(rd());
                
                stringstream ss;
                for (int i = 0; i < 12; ++i) {
                    uint8_t byte = static_cast<uint8_t>(gen() & 0xFF);
                    ss << hex << setw(2) << setfill('0') << (int)byte;
                }
                string id = ss.str();
                transform(id.begin(), id.end(), id.begin(), ::toupper);
                return id;
            }
            
            bool pbxUUID::containObject(vector<string> uuids, string contain){
                
                for(auto itr = uuids.begin(); itr != uuids.end(); ++itr){
                    if(contain==*itr)
                        return true;
                }
                return false;
            }
        }
    }
}
