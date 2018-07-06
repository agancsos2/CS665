# Namespace Test
* Author    : Abel Gancsos
* Version   : v. 1.0.0

## Purpose
The purpose of this project is to act as a proof of concept on how namespaces work in C++.  This is a very basic example; however, can show the very novoce C++ developer on how they can be used to better their code.

## Why would they be used?
The main benefit of using namespaces is to avoid name conflicts and therefore avoiding using the incorrect implementation when making the calls. It also offers a nice way to organize your code and enables you to use STL functions.
One obvious reason to use it mayu be so that you don't have ti include all of your header files; however, as we will later see, you stil need an all header file to use the namespace.

## Prerequisites
### G++ compiler
#### Windows
Should come with Visual Studio 2017 in the form of devenv, but you can also try using Bloodshed Dev C++
#### Mac
Should come with XCode command-line tools
#### Linux
Should be installable using internal package installer
### CMake
#### Windows
Should come with Visual Studio 2017 
#### Mac
Can be installed from https://cmake.org/download/
#### Linux
Can be installed from https://cmake.org/download/

## Build
This can be built either using one of the run scripts or manually using the following instructions
### Windows
* Import into a new C++ project
* Build using Visual Stuido 2017

### Mac
Either import it into a new XCode project or compile on the command-line using g++ -std=c++11

### Linux
Compile using g++ -std=c++11

## Execute
Run the target that was generated in the build step
​
