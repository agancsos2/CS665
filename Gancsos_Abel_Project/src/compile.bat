@echo off

REM ##############################################################################
REM Name        : make                                                           #
REM Author      : Abel Gancsos                                                   #
REM Version     : v. 1.0.0                                                       #
REM Description : Helps build project package on a non-Windows system            #
REM ##############################################################################

set APP_ROOT=".\"
set VS_PATH="C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\Common7\IDE"
set CMAKE_PATH=%VS_PATH%"\CommonExtensions\Microsoft\CMake\CMake\bin"

del /S /Q %APP_ROOT%\..\bin\*
rmdir /S /Q %APP_ROOT%\..\bin\amgpetagency.dir
cd %APP_ROOT%\..\bin & %CMAKE_PATH%\cmake ..\
cd %APP_ROOT%\..\bin && %VS_PATH%\devenv.exe Gancsos_Abel_Project.sln /build
rmdir /S /Q %APP_ROOT%\..\bin\amgpetagency.dir
rmdir /S /Q %APP_ROOT%\..\bin\CMakeFiles
rmdir /S /Q %APP_ROOT%\..\bin\Win32
rmdir /S /Q %APP_ROOT%\..\bin\.vs
del /S /Q %APP_ROOT%\..\bin\*.cmake
del /S /Q %APP_ROOT%\..\bin\*.sln
del /S /Q %APP_ROOT%\..\bin\CMake*.txt
del /S /Q %APP_ROOT%\..\bin\*.vcxproj*
xcopy /S /Q %APP_ROOT%\..\bin\Debug\amgpetagency.exe %APP_ROOT%\..\bin\
rmdir /S /Q %APP_ROOT%\..\bin\Debug
