cmake_minimum_required(VERSION 2.8)
add_definitions("-Wall -std=c++0x")
project(PBXObject CXX)
set("1.0.0")
include_directories(./src/xcodeproj/pbxproj/pbxObject)
include_directories(./src/option.h)
add_executable(PBXProject ./src/main.cpp
			  ./src/option.cpp
		      ./src/xcodeproj/pbxproj/pbxObject/Util.cpp
		      ./src/xcodeproj/pbxproj/pbxObject/pbxCreate.cpp
		      ./src/xcodeproj/pbxproj/pbxObject/pbxObjectSection.cpp
		      ./src/xcodeproj/pbxproj/pbxObject/pbxParser.cpp
		      ./src/xcodeproj/pbxproj/pbxObject/pbxProject.cpp
		      ./src/xcodeproj/pbxproj/pbxObject/pbxUUID.cpp
		      ./src/xcodeproj/pbxproj/pbxObject/pbxWriter.cpp)

