//
//  pbxCreate.cpp
//  PBXObject
//
//  Created by shichimi on 2017/01/31.
//  Copyright © 2017年 shichimitoucarashi. All rights reserved.
//
//  The license is Apache, please see the link below
//  https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE
//
//

#include "pbxCreate.hpp"
#include <random>
#include <iostream>
#include <map>
#include "pbxUUID.hpp"
#include "pbxObjectSection.h"
#include "Util.h"

using namespace xcodeproj::pbxproj::pbxObject;

#define XCASSETS_EXTENTION "xcassets"
#define REPLACE_CHARACTER  "replaceStr"

namespace xcodeproj {
    namespace pbxproj{
        namespace pbxObject {

            string pbxContainerItem::pbxContainerItemProxy(string uuid, string containerUuid, string projName, string remoteGlobalID){
                return BeginPBXContainerItemProxy + "\n\t\t" + uuid + " /* PBXContainerItemProxy */ = {\n\t\t\tisa = PBXContainerItemProxy;\n\t\t\tcontainerPortal = " + containerUuid + " /* " + projName + " */;\n\t\t\tproxyType = 2;\n\t\t\tremoteGlobalIDString = " + remoteGlobalID + ";\n\t\t\tremoteInfo = " + Util::removeExtention(projName) + ";\n\t\t};\n" + EndPBXContainerItemProxy;
           }

            string pbxBuildObject::pbxBuildCreater(string uuid, string fileName,string fileRef){
                return "\t\t" + uuid + " /* " + fileName + " in " + pbxCreate::fileType(fileName) + " */ = {isa = PBXBuildFile; fileRef = " + fileRef + " /* " + fileName + " */; };";
            }

            string pbxReferenceObject::pbxReferenceCreater(string uuid, string fileName){
                return "\t\t" + uuid + " /* " + fileName + " */ = {isa = PBXFileReference; " + pbxCreate::fileEncoding(fileName) + " lastKnownFileType = " + pbxCreate::filelastKnownFileType(fileName) + " path = " + Util::escapeCode(fileName) + "; sourceTree = \"<group>\"; };";
            }

            string pbxReferenceObject::pbxReferenceCreate(string uuid, string fileName, string name, string lastKnownFileType){
                 return "\t\t" + uuid + " /* " + fileName + " */ = {isa = PBXFileReference; " + pbxCreate::fileEncoding(fileName) + " lastKnownFileType = " + pbxCreate::filelastKnownFileType(lastKnownFileType) + " name = " + fileName + ";" + " path = " + Util::escapeCode(name) + "; sourceTree = \"<group>\"; };";
            }

            string pbxGroupObject::pbxGroupCreater(string uuid,string parent, vector<pbxChildren> chilren){
                return "\t\t" + uuid + " /* " + parent + " */ = {\n\t\tisa = PBXGroup;\n\t\t\tchildren = (\n" + pbxCreate::listOfChildren(chilren) + "\t\t\t);\n\t\tpath = " + Util::escapeCode(parent) + ";\n\t\tsourceTree = \"<group>\";\n\t\t};\n";
            }

            string pbxVariantGroupSection::pbxVariantGroupSectionCreate(string uuid, string lprojUuid, string fileName, string lprojName){
                return "\t\t" + uuid + " /* " + fileName + " */ = {\n\t\tisa = PBXVariantGroup;\n\t\t\tchildren = (\n\t\t\t\t" + lprojUuid + " /* " + lprojName + " */,\n\t\t\t);\n\t\t\tname = " + fileName + ";\n\t\t\tsourceTree = \"<group>\";\n\t\t};";
            }

            string pbxCreate::listOfChildren(vector<pbxChildren> childrens){
                string pbxList;
                for(auto pbxItr = childrens.begin(); pbxItr != childrens.end(); ++pbxItr){
                    pbxList += "\t\t\t\t" + pbxItr->uuid + " /* " + pbxItr->filename + " */,\n";
                }
                return pbxList;
            }

            string pbxBuildFramework::pbxBuildFrameworkCreater(vector<pbxChildren> files){
                return pbxCreate::listOfChildren(files);
            }

            string pbxSourceBuildObject::pbxSourceBuildCreater(vector<pbxChildren> files){
                return pbxCreate::listOfChildren(files);
            }

            string pbxResrouceBuildObject::pbxResourceBuildCreater(vector<pbxChildren> files){
                return pbxCreate::listOfChildren(files);
            }

            string pbxCreate::filelastKnownFileType(string file){

                string ext = Util::pathExtention(file);
                map<string, string>fileKnownType = {
                    {"m", "sourcecode.c.objc;" },
                    {"h", "sourcecode.c.h;"},
                    {"c", "sourcecode.c.c;" },
                    {"cpp","sourcecode.cpp.cpp;"},
                    {"swift","sourcecode.swift;"},
                    {"hpp","sourcecode.cpp.h;"},
                    {"framework", "wrapper.framework;"},
                    {"s", "sourcecode.asm;"},
                    {"a", "archive.ar;"},
                    {"png","image.png;"},
                    {"jpg","image.jpeg;"},
                    {"bundle","\"wrapper.plug-in\";"},
                    {"plist" , "text.plist.xml;"},
                    {"storyboard", "file.storyboard;"},
                    {"xib", "file.xib;"},
                    {"xcassets","folder.assetcatalog;"},
                    {"json","text.json;"},
                    {"ttf","file;"},
                    {"xcodeproj","\"wrapper.pb-project\";"},
                    {"pl","text.script.perl;"},
                    {"pm","text.script.perl;"},
                    {"xcassets","folder.assetcatalog;"}
                };
                if(fileKnownType[ext]=="")return "text;";
                return fileKnownType[ext];
            }

            string pbxCreate::fileEncoding(string file){
                string file_extention = Util::pathExtention(file);
                string fileType;
                if(file_extention.find("m")
                   || file_extention.find("h")
                   || file_extention.find("cpp")
                   || file_extention.find("hpp")){

                    fileType = "fileEncoding = 4;";

                }else
                    fileType = "";

                return fileType;
            }

            string pbxCreate::fileType(string fileName){
                string file_extention = Util::pathExtention(fileName);
                string fileType;
                if(file_extention.find("m")
                   || file_extention.find("h")
                   || file_extention.find("cpp")
                   || file_extention.find("hpp")
                   || file_extention.find("c")
                   || file_extention.find("java")
                   || file_extention.find("rb")
                   || file_extention.find("cc")
                   || file_extention.find("pl")){

                    fileType = "Sources";

                }else if(file_extention.find("framework")
                         || file_extention.find("a")){

                    fileType = "Frameworks";

                } else
                    fileType = "Resources";

                return fileType;
            }

            pbxChildren pbxCreate::pbxies(string uuid, string file){
                pbxChildren pbxChild;
                pbxChild.uuid = uuid;
                pbxChild.filename = file;
                return pbxChild;
            }

            pbxVarient pbxCreate::pbxVarientDtoCreate(string lprojName,string lprojUuid){
                pbxVarient pbxVS;
                pbxVS.lProjUuid = lprojUuid;
                pbxVS.lProjName = lprojName;
                return pbxVS;
            }

            string pbxCreate::createPhase(string uuid, string file){
                return "\t\t\t\t" + uuid + " /* "  + file + " in " + pbxCreate::fileType(file) + " */,";
            }

            string pbxCreate::createPbxies(string uuid, string file){
                return "\t\t\t\t" + uuid + " /* "  + file + " */,";
            }

            bool pbxCreate::isSourceFile(string path){

                if(Util::pathExtention(path)=="m"
                    || Util::pathExtention(path)=="mm"
                    || Util::pathExtention(path)=="cpp"
                    || Util::pathExtention(path)=="c"
                    || Util::pathExtention(path)=="cc"
                    || Util::pathExtention(path)=="swift"){
                    return true;
                }
                return false;
            }

            bool pbxCreate::isBundleFile(string path){
                if(Util::pathExtention(path)=="framework"
                    || Util::pathExtention(path)=="bundle"
                    || Util::pathExtention(path)=="xcodeproj"
                    || Util::pathExtention(path)==XCASSETS_EXTENTION){
                    return true;
                }
                return false;
            }

            bool pbxCreate::isLibFile(string path){
                if(Util::pathExtention(path)=="framework"
                    || Util::pathExtention(path)=="a"
                    || Util::pathExtention(path)=="tbd"){
                    return true;
                }
                return false;
            }

            bool pbxCreate::isHeaderFile(string path){
                if(Util::pathExtention(path)=="h"
                    || Util::pathExtention(path)=="hpp"){
                    return true;
                }
                return false;
            }

            bool pbxCreate::islprojFile(string path){
                if (Util::pathExtention(path)=="lproj"){
                    return true;
                }
                return false;
            }

            bool pbxCreate::isXibfile(string path){
                if (Util::pathExtention(path)=="storyboard"){
                    return true;
                }
                return false;
            }

            vector<string> pbxCreate::pbxObjectCreater(string path){

                vector<string> results;
                vector<string> dirs;

                string parentFile = Util::lastPath(path);
                string parentUuid = pbxUUID::getInstance()->pbxGenerater(path);
                vector<pbxChildren> groupChildren;

                if(this->parentPath.length() == false)
                    this->parentPath = createPbxies(parentUuid, parentFile);

                vector<string> lists = Util::listDirectory(path.c_str());

                if(lists.size()!=false){

                    for(auto itr=lists.begin(); itr != lists.end(); ++itr){

                        string full_path = *itr;

                        string lastPathComponent = Util::lastPath(full_path);
                        if(lastPathComponent.find(".DS_Store")==false
                           || lastPathComponent.find(".git")==false)continue;

                        string uuid_s = pbxUUID::getInstance()->pbxGenerater(full_path);

                        pbxChildren pbxChild = pbxies(uuid_s, lastPathComponent);
                        if (islprojFile(lastPathComponent) == false){
                              groupChildren.push_back(pbxChild);
                        }

                        if(Util::isDirectory(full_path.c_str())){

                            string buildUuid = pbxUUID::getInstance()->pbx_uuid_generater(lastPathComponent);

                            if(Util::pathExtention(lastPathComponent)==XCASSETS_EXTENTION){
                                this->pbxResourcies.push_back(createPhase(buildUuid, lastPathComponent));
                                this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, pbxChild.uuid));
                            }

                            if(islprojFile(lastPathComponent)){

                                vector<string> lprojs = Util::listDirectory(full_path.c_str());

                                for (auto lpj = lprojs.begin(); lpj != lprojs.end(); ++lpj){

                                    string lprojPath = *lpj;
                                    string lprojKey = *lpj;
                                    string storyboardName = Util::lastPath(lprojPath);

                                    string parentlproj = Util::removeExtention(lastPathComponent);
                                    lprojPath = lastPathComponent + "/" + storyboardName;
                                    string lProjFileName = Util::lastPath(full_path.c_str());
                                    string lprojUUID = pbxUUID::getInstance()->pbxGenerater(lprojKey);
                                    string uuidLproj = pbxUUID::getInstance()->pbxGenerater(lprojPath);

                                    pbxChildren lprojPbx = pbxies(uuidLproj, Util::lastPath(storyboardName));

                                    this->lprojMap[lprojKey] = lprojPbx;
                                    groupChildren.push_back(lprojPbx);

                                    this->pbxReferencies.push_back( pbxReferenceObject::pbxReferenceCreate(lprojUUID,parentlproj,lprojPath,lprojPbx.filename));

                                    string refe = pbxReferenceObject::pbxReferenceCreate(lprojUUID,parentlproj,lprojPath,lprojPbx.filename);

                                    this->pbxVariants.push_back( pbxVariantGroupSection::pbxVariantGroupSectionCreate(lprojPbx.uuid,
                                                                                                                      lprojUUID,
                                                                                                                      storyboardName,
                                                                                                                      parentlproj
                                                                                                                    ));

                                }
                            }

                            if(isBundleFile(lastPathComponent))
                                this->pbxReferencies.push_back( pbxReferenceObject::pbxReferenceCreater(pbxChild.uuid, pbxChild.filename));

                            if(Util::pathExtention(lastPathComponent)=="xcodeproj"){
                                string pbxItemVal = pbxContainerItem::pbxContainerItemProxy(pbxUUID::getInstance()->pbxGenerater(full_path),
                                    pbxChild.uuid,
                                     lastPathComponent,
                                     pbxUUID::getInstance()->pbxGenerater(full_path));
                                this->pbxContainer.push_back(pbxItemVal);
                            }

                            if(isBundleFile(lastPathComponent)==false)
                                dirs.push_back(full_path);

                        }else{
                            if(isXibfile(lastPathComponent)==false)
                                pbxReferencies.push_back( pbxReferenceObject::pbxReferenceCreater(pbxChild.uuid, pbxChild.filename));

                            string buildUuid = pbxUUID::getInstance()->pbx_uuid_generater(lastPathComponent);

                            pbxChildren lprojChild = this->lprojMap[full_path];

                            if (lprojChild.uuid != ""){
                              this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, lprojChild.uuid));
                              this->pbxResourcies.push_back(createPhase(buildUuid, lastPathComponent));
                            }else{
                              if(isSourceFile(lastPathComponent)==true){
                                  this->pbxSourcies.push_back(createPhase(buildUuid, lastPathComponent));
                                  this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, pbxChild.uuid));
                              }
                              else if(isLibFile(lastPathComponent)==true){
                                  this->pbxFrameworks.push_back(createPhase(buildUuid, lastPathComponent));
                                  this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, pbxChild.uuid));
                              }
                              else if(isHeaderFile(lastPathComponent)==false){
                                  this->pbxResourcies.push_back(createPhase(buildUuid, lastPathComponent));
                                  this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, pbxChild.uuid));
                              }
                            }
                        }
                    }
                    //PBX Group Create;
                    if (islprojFile(parentFile) == false)
                        this->pbxGroups.push_back( pbxGroupObject::pbxGroupCreater(parentUuid, parentFile, groupChildren));

                    for(auto itr = dirs.begin(); itr != dirs.end(); ++itr){
                        string dir_path = *itr;
                        vector<string> sub_dir = pbxObjectCreater(dir_path);
                        results.insert(results.end(), sub_dir.begin(), sub_dir.end());
                    }

                }else{

                    string lastPathComponent = Util::lastPath(path);

                    string uuid_s = pbxUUID::getInstance()->pbxGenerater(path);

                    pbxChildren pbxChild = pbxies(uuid_s, lastPathComponent);

                    pbxReferencies.push_back( pbxReferenceObject::pbxReferenceCreater(pbxChild.uuid, pbxChild.filename));

                    string buildUuid = pbxUUID::getInstance()->pbx_uuid_generater(lastPathComponent);

                    if(isSourceFile(lastPathComponent)==true){
                        this->pbxSourcies.push_back(createPhase(buildUuid, lastPathComponent));
                        this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, pbxChild.uuid));
                    }
                    else if(isLibFile(lastPathComponent)==true){
                        this->pbxFrameworks.push_back(createPhase(buildUuid, lastPathComponent));
                        this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, pbxChild.uuid));
                    }
                    else if(isHeaderFile(lastPathComponent)==false){
                        this->pbxResourcies.push_back(createPhase(buildUuid, lastPathComponent));
                        this->pbxBuilds.push_back( pbxBuildObject::pbxBuildCreater(buildUuid, lastPathComponent, pbxChild.uuid));
                    }
                }
                return results;
            }
        }
    }
}
