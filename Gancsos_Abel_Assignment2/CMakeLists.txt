###############################################################################
## Name        : CMakeLists                                                   #
## Author      : Abel Gancsos                                                 #
## Version     : v. 1.0.0                                                     #
## Description : Build configuration file                                     #
## Based on example: https://bit.ly/2lNz6gb                                   #
###############################################################################

cmake_minimum_required(VERSION 3.11) ## Version of cmake needed
project(Gancsos_Abel_Assignment2)    ## Root folder/project name

###############################################################################
#                          Glob files in source                               #
###############################################################################
file(GLOB_RECURSE sources src/main.cpp src/classes/*.cpp src/classes/*.h)
## file(GLOB_RECURSE sources_test test/*.cpp) ## Unit Testing
file(GLOB_RECURSE data resources/*)
list(FILTER sources EXCLUDE REGEX ".*.(cpp | h)" )
###############################################################################

add_executable(amgdeliverydispatch ${sources} ${data})

###############################################################################
#                         Compiler options                                    #
###############################################################################
target_compile_options(amgdeliverydispatch PUBLIC -std=c++11)

###############################################################################
#                        Set project includes                                 #
###############################################################################
target_include_directories(amgdeliverydispatch PUBLIC src)

###############################################################################
#                        Package resources                                    #
###############################################################################
file(COPY ${data} DESTINATION resources)

###############################################################################
#                         Package project                                     #
###############################################################################
install(TARGETS amgdeliverydispatch DESTINATION bin)
install(DIRECTORY resources DESTINATION bin)

###############################################################################
#                         Package information                                 #
############################################################################### 
set(CPACK_PACKAGE_NAME "Gancsos_Abel_Assignment2")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_MONOLITHIC_INSTALL 1)
include(CPack)
