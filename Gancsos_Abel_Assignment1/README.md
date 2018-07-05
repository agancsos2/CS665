# README                                    

## ABOUT                               
* NAME       : AMGVending
* Author     : Abel Gancsos
* Version    : v. 1.0.0

## Implementation Details  
The following utility, AMGVending, acts as a controller for a new fully automated beverage vending machine.  
This is to say that run in interactive mode, the utility should be prepared for a customer by having an available prompt, in this case in a shell command window.  
Once a patron arrives and is ready to order, they select from the menu options the type of drink they are interested in.  
The controller then prompts for the subtype or sort of drink the patron would like to have, and then it prompts the patron if they would like any toppings or condiments.  
If the patron selects to add condiments, the controller then displays a menu option for available condiments.  
The vending machine then prompts the patron for quantity of the condiment, which must be within the valid scope.  
Then vending machine then prepares the drink and dispenses it to the patron.  The controller then goes back to the main menu for the next transaction.
In order to handle future drink types, the controller uses abstract classes for the drink objects.  As for the drink sorts, each derived class of the abstract drink type comes with a sort enum, which 
will be primarily used for input validation.  As for the condiments, we use another abstract class as we suspect that additional condiments might be added in the future.
The controller then uses a "session" class as a wrapper to build out the transaction, which holds details of the selected options.

### Drink types
* Coffee
     * Espresso
     * Americano
     * Latte Macchiato
* Tea
     * Black Tea
     * Green Tee
     * Yellow Tea     

### Condiments 
* milk
* sugar  

## Assumptions:
* The dispensing mechanism works or the software group is not responsible for any mechanical bugs.  
* Maybe some day the vending machine is to be run in a batchable mode, therefore, certain switches or flags are built into the controller. 
* Additional drink types will be added in the future.
* Additional drink sorts will be added in the future.
* Additional drink condiments will be added in the future.
* The restriction on drink condiment quantity may be raised or lifted completed.
* The payment has already been provided before the controller is used.
       
## Implementation Description
*How is the flexibility, of your implementation, e.g., how you add or remove in future new drink types?
* How is the simplicity and understandability of your implementation?
* How you avoided duplicated code?

In case that you have used any design patterns, describe which design pattern you have applied and why.
                    

## FLAGS                                    
* -drink      : Applicable drink type
* -sort       : Applicable drink subtype
* -condiments : Comma-separated list of applicable drink condiments
* -amount     : Comma-separated list of applicable drink condiment quanity.  0-3.  Value must match the index in the condiments list
* \#           : Not really a flag, but can be used to exit interactive mode

## CONFIGURATION                                  
### INSTALLATION                                
* Install a g++ compile and ensure that the g++ binary is in the Path variable.
    * Windows : Visual Studio
    * MacOS   : Install via XCode command-line tools
    * Linux   : Install using internal installer 

* Download and install CMake from https://cmake.org/download/

* Build the project using make.sh or make.bat

## Executing                                
Run the utility via the command-line from the bin directory via ./ . 
