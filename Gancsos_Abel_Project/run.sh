#!/bin/bash
###############################################################################
## Name        : make                                                         #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Helps build project package on a non-Windows system          #
###############################################################################

APP_ROOT=$(dirname "$0")
$APP_ROOT/src/compile.sh

$APP_ROOT/bin/amgpetagency -m 1
$APP_ROOT/bin/amgpetagency -m 2
$APP_ROOT/bin/amgpetagency -m 3
$APP_ROOT/bin/amgpetagency -m 4 -row 0
$APP_ROOT/bin/amgpetagency -m 5 -row 0
