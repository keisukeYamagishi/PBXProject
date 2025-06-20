# PBXObject

[![](https://img.shields.io/badge/Language-C%2B%2B-ff69b4.svg)](https://isocpp.org/)
[![](https://img.shields.io/badge/license-Apache-orange.svg)](https://github.com/keisukeYamagishi/PBXProject/blob/master/LICENSE)

# Build
|OS		 |Result	   |
|:---------------|:----------------|
| ***mac OS X*** |[![C/C++ CI](https://github.com/keisukeYamagishi/PBXProject/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/keisukeYamagishi/PBXProject/actions/workflows/c-cpp.yml)|

# Overview

PbxObject controls Xcode's file detection system.
For example, when adding files to Xcode, you can add files with pbxObject and let Xcode detect them instead of dragging and dropping.

## git clone

***Via SSH***: For those who plan on regularly making direct commits, cloning over SSH may provide a better experience (which requires uploading SSH keys to GitHub):

```
mkdir gitrepo

cd gitrepo

git cloen git@github.com:keisukeYamagishi/PBXProject.git

```

***Via https***: For those checking out sources as read-only, HTTPS works best:

```
mkdir gitrepo

cd gitrepo

git clone https://github.com/keisukeYamagishi/PBXProject.git

```

### Build 

#### Get CMake(mac OS only)


Please install the .dmg file of Mac OSX 10.6 or later list. Please run it if you want to install the following command.

***homebrew***

```
brew install cmake
```

Check whether cmake has been installed or not by the following command.

```
cmake --version
```
If cmake's version is displayed installation is complete, detect's Cmake version will be 2.7. If it is more than that, you can build it.

### 　mac OS X(mac OS X only)

MakeFile is output if you move to the immediate clone source directory and execute the cmake command, please execute the make command, if executed, the detect binary will be output.

```
cd /source_directory/gitrepo

cmake .

make 

```
# Run 

You can add the file you want to add to xcodeproj by passing the path of xcodeproj you want to add and the file you want to add as an argument.

# Option

```

usage: PBXProject [-v] [<path>] [-a addFile=value] [-o output]

These are common detect commands used in various situations:

PBXProject version: 1.0.0

option: 
-v:  display PBXProject version number
-o:  output result
-a:  add File or directory


Best Regars !

```

*** -v *** 

Dispaly PBXProject version number

*** -o ***

output result

*** -a ***

add File or Directory

# Use it

```
./PBXProject /Users/shichimi/Desktop/PBXApps/PBXApps.xcodeproj -a  /Users/shichimi/Documents/take_photo/take_n_photo/ViewController -o 

// !$*UTF8*$!
{
	archiveVersion = 1;
	classes = {
	};
	objectVersion = 46;
	objects = {

/* Begin PBXBuildFile section */
		00734683CCD4FC681FA93280 /* animateClass.m in Sources */ = {isa = PBXBuildFile; fileRef = E55F132D292C77DD274566D5 /* animateClass.m */; };
		00EFE3092A298143A0E21E03 /* BCPrefix.pch in Resources */ = {isa = PBXBuildFile; fileRef = 17910A509A1606A7C4B283D8 /* BCPrefix.pch */; };
		02BCFA34CAAD77DD125E3250 /* normal.png in Resources */ = {isa = PBXBuildFile; fileRef = 94B3F6B64D27E409CE39F88E /* normal.png */; };
		02DE44D04F4AB3959F088820 /* selectImage.m in Sources */ = {isa = PBXBuildFile; fileRef = 
......
....
...
..
.
any ...
any..
any.

```

**output**
```
// !$*UTF8*$!
{
	archiveVersion = 1;
	classes = {
	};
	objectVersion = 46;
	objects = {

/* Begin PBXBuildFile section */
		F0F5E3101E861BE900F2C2AA /* main.m in Sources */ = {isa = PBXBuildFile; fileRef = F0F5E30F1E861BE900F2C2AA /* main.m */; };
		F0F5E3131E861BEA00F2C2AA /* AppDelegate.m in Sources */ = {isa = PBXBuildFile; fileRef = F0F5E3121E861BEA00F2C2AA /* AppDelegate.m */; };
		F0F5E3161E861BEA00F2C2AA /* ViewController.m in Sources */ = {isa = PBXBuildFile; fileRef = F0F5E3151E861BEA00F2C2AA /* ViewController.m */; };
		F0F5E3191E861BEB00F2C2AA /* Main.storyboard in Resources */ = {isa = PBXBuildFile; fileRef = F0F5E3171E861BEB00F2C2AA /* Main.storyboard */; };
		F0F5E31B1E861BEB00F2C2AA /* Assets.xcassets in Resources */ = {isa = PBXBuildFile; fileRef = F0F5E31A1E861BEB00F2C2AA /* Assets.xcassets */; };
		F0F5E31E1E861BEB00F2C2AA /* LaunchScreen.storyboard in Resources */ = {isa = PBXBuildFile; fileRef = F0F5E31C1E861BEB00F2C2AA /* LaunchScreen.storyboard */; };
		DC851A9C40471E2CB83A38EE /* animationClass.m in Sources */ = {isa = PBXBuildFile; fileRef = 29015FA5A81DE48E1365C055 /* animationClass.m */; };
		5FCD56FC441AAF5917C9EFB6 /* laserBeam.m in Sources */ = {isa = PBXBuildFile; fileRef = 3A94BDEDEBC034C5D7EB853B /* laserBeam.m */; };
		F8AAF9116F95915E712C3871 /* pbx_option.cpp in Sources */ = {isa = PBXBuildFile; fileRef = 0450EC985F3A406C23DE510C /* pbx_option.cpp */; };
		E526007A0C9A569C9FB6A645 /* pbxCreate.cpp in Sources */ = {isa = PBXBuildFile; fileRef = B0C827CDB057F2DC954B636C /* pbxCreate.cpp */; };
		228CFF923132FF
    any.....
    any...
    any..
    any.

```

# Sample code

```
    /*
     * Specify the path of the xcodeproj file you want to add.
     *
     */
    string path = string("/Users/shichimi/PBXApps/PBXApps.xcodeproj");
    
    /*
     * Specify the file path to add
     *
     */
    string add_path = "/Users/shichimi/PBXAddedFile/";
    
    pbxProject pbxproj = pbxProject(path);
    
    pbxproj.addPBXProject(add_path);

```


