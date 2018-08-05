# README                                    

## ABOUT                               
* NAME       : AMGPetAgency
* Author     : Abel Gancsos
* Version    : v. 1.0.0

## Introduction
With more and more pets being abandoned or removed from an abusive household, leading to more homeless animals, there is a higher need find adoptive parents for these pets.  AMGPetAgency thus so happens to be one of these organizations that strives to place animals with the most appropriate adoptive parents based on personality traits, work schedule, family size, and overall lifestyle.  However, because of the recent increase in demand, AMGPetAgency’s paper-copy approach isn’t working too well, leading to data loss, ranging from the very minor details to losing documentation.  In all honesty, this issue only started recently and the president is looking for an immediate solution.  

The president met up with a software developer friend and they came up with a suggestion to build a record management system in order to know which animal is placed in which home as well as which animals are still available for adoption.  The end result would be a custom application that can be accessed only on the internal network from any machine and would be scalable to handle the large number of animals needed to be adopted.  In order to get a better understanding of the system details, the president requested the development team to build a prototype that demonstrates the overall features that will be available in the initial release.

## Implementation Details 
This utility, AMGPetAgency, is a prototype system controller that helps keep pet adoption records safe and organized in one central location.  The current prototype uses an in-memory database (collections) to store the records and is able to demonstrate the bulk of the functionality of the final product.  The controller uses a command-line input mechanism to prompt the user to required details to construct a new person to add to the system or a new pet that is available for adoption.  The controller then uses the array indices for the records when prompting the user to adopt a new pet or to return a pet that can no longer be kept in the current home. 

During the prompt to adopt, the controller will display a list of available pets to adopt, will validate the input from the user, and will also display a list of all people that are able to adopt a pet.  During the return process, the controller will ask for a confirmation if the user really wants to return the pet and will then display a list of adopted pets.  If the user input is not valid, either because it’s not in a numeric form or is out of scope of the collection, a message will be displayed and/or the error will be corrected by reapplying a default value.   

In the event that the prototype does become a CLI (command-line interface) for the final product, additional feature may be added, such as searching for a specific pet or a specific person.  The key aspect of the controller is being able to smoothly build a complete object such as a dog or person since the rest of the operations are just input/output.

## Assumptions:
*	The animal breeds have already been breaded and are available for appropriate animals.
*	Animal types are predefined and no new animal can bee created via combinations.
*	A person can only be either a male, female, or not specified.
*	The measurement used for height is in inches.
*	The measurement used for weight is pounds.
*	Additional nationalities will be added in the future.
*	Additional races will be added in the future.
*	Additional animal breeds will be added in the future.
*	Additional animal types will be added in the future.
*	Additional properties will be added and be configurable to people in the future.
*	Additional properties will be added and be configurable to animals in the future.
       
## FLAGS                                    
* -m   : Appropriate numeric menu value for the operation to perform.
* -row : Row index for the value in the list

## Modes (Batchable)
* 0  : Exit
* 1  : List People
* 2  : List Available Pets
* 3  : List Adopted Pets
* 4  : Adopt Pet
* 5  : Return Pet

## Implementation Description


## PREREQUISITES
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
