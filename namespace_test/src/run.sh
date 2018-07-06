#!/bin/bash
###############################################################################
## Name        : make                                                         #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Helps build project package on a non-Windows system          #
###############################################################################

APP_ROOT=$(dirname "$0")
CMAKE_PATH="/Users/computerfox/Downloads/cmake-3.12.0-rc2/Bootstrap.cmk"

rm -fR $APP_ROOT/../bin/*
cd $APP_ROOT/../bin && $CMAKE_PATH/cmake ../
cd $APP_ROOT/../bin && make

rm $APP_ROOT/../bin/*.cmake
rm -fR $APP_ROOT/../bin/CMakeFiles
rm $APP_ROOT/../bin/Makefile
rm $APP_ROOT/../bin/CMake*.txt
