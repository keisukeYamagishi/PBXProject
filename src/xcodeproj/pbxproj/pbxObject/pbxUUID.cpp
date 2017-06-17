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
                
                std::string pbxuuid ="";
                
                while (pbxUUID::containObject(pbxUUID::getInstance()->uuidStore, pbxuuid)==false) {
                    std::random_device rnd;
                    std::mt19937 mt(rnd());
                    std::uniform_int_distribution<int> rand5(0,15);
                    
                    for (int i = 0; i < 24; i++)
                        pbxuuid +=  pbxUUID::pbx_uuid_string(rand5(mt));
                    
                    pbxUUID::getInstance()->uuidStore.push_back(pbxuuid);
                }
                return pbxuuid;
            }
            
            
            string pbxUUID::pbx_uuid_string(int index){
                string  uuidCharacter[16] = {
                    "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"
                };
                return uuidCharacter[index];
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
