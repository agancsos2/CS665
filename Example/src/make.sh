#!/bin/bash
###############################################################################
## Name        : make                                                         #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Helps build project package on a non-Windows system          #
###############################################################################

APP_ROOT=$(dirname "$0")
CMAKE_PATH=""

rm -fR $APP_ROOT/../bin/*
cd $APP_ROOT/../bin && $CMAKE_PATH/cmake ../
cd $APP_ROOT/../bin && make
