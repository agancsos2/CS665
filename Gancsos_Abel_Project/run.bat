@echo off

REM ##############################################################################
REM Name        : make                                                           #
REM Author      : Abel Gancsos                                                   #
REM Version     : v. 1.0.0                                                       #
REM Description : Helps build project package on a non-Windows system            #
REM ##############################################################################

.\src\compile.bat

.\bin\amgpetagency.exe -m 1
.\bin\amgpetagency.exe -m 2
.\bin\amgpetagency.exe -m 3
.\bin\amgpetagency.exe -m 4 -row 0
.\bin\amgpetagency.exe -m 5 -row 0
