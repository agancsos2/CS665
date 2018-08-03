#!/bin/bash
###############################################################################
## Name        : make                                                         #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Helps build project package on a non-Windows system          #
###############################################################################

APP_ROOT2=$"$( cd "$(dirname "$0")" ; pwd -P )"
echo $APP_ROOT2
CMAKE_PATH=""

rm -fR $APP_ROOT2/../bin/*
cd $APP_ROOT2/../bin && $CMAKE_PATH/cmake ../
cd $APP_ROOT2/../bin && make

rm $APP_ROOT2/../bin/*.cmake
rm -fR $APP_ROOT2/../bin/CMakeFiles
rm $APP_ROOT2/../bin/Makefile
rm $APP_ROOT2/../bin/CMake*.txt
