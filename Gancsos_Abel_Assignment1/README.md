# README                                    

## ABOUT                               
* NAME       : AMGVending
* Author     : Abel Gancsos
* Version    : v. 1.0.0

## Implementation Details  
The following utility, AMGVending, acts as a controller for a new fully automated beverage vending machine.  This is to say that run in interactive mode, the utility should be prepared for a customer by having an available prompt, in this case in a shell command window.  Once a patron arrives and is ready to order, they select from the menu options the type of drink they are interested in.  The controller then prompts for the subtype or sort of drink the patron would like to have, and then it prompts the patron if they would like any toppings or condiments.  If the patron selects to add condiments, the controller then displays a menu option for available condiments.  The vending machine then prompts the patron for quantity of the condiment, which must be within the valid scope.  Then vending machine then prepares the drink and dispenses it to the patron.  The controller then goes back to the main menu for the next transaction.

In order to handle future drink types, the controller uses abstract classes for the drink objects.  As for the drink sorts, each derived class of the abstract drink type comes with a sort enum, which will be primarily used for input validation.  As for the condiments, we use another abstract class as we suspect that additional condiments might be added in the future.

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

### Assumptions:
* The dispensing mechanism works or the software group is not responsible for any mechanical bugs.  
* Maybe some day the vending machine is to be run in a batchable mode, therefore, certain switches or flags are built into the controller. 
* Additional drink types will be added in the future.
* Additional drink sorts will be added in the future.
* Additional drink condiments will be added in the future.
* The restriction on drink condiment quantity may be raised or lifted completed.
* The payment has already been provided before the controller is used.
       
## Implementation Description
This utility was implemented using abstract classes due to their many benefits towards the functionality of the project.  For example, because it is expected that there will be new drink types added, an abstract class, VendingDrink, was created to manage the base structure.  This base structure would then be inherited by any new drink type, for which certain operations would be implemented using polymorphism in order to provide appropriate results for the new drink.  So in order to add a new drink type or remove an existing one, the class simply needs to implement the abstract methods or the class should simply be removed.

An abstract class not only serves as a class which child classes will inherit the base characteristics, but also provides a way to dynamically iterate through a collection of drink objects by calling the abstract methods.  When the abstract method is called against the base class within the iteration, what actually happens is that the implementation is called against the child class.  This is possible since VendingDrink cannot be instantiated, only through the child class that implements the abstract methods.  This then provides the actual drink type, but represented as the abstract VendingDrink object.

Another design approach that was used was helper classes.  Although this is a very basic concept, by using the helper class, AMGVendingHelpers, this offered a way to call common blocks of code in different areas of the program.  By having a central location where these methods could be called from, duplication of code can be avoided.

When it comes to simplicity and understandability, the utility attempts to address both concerns by using small methods.  When the methods started to get quite large, it was hard to follow, so the large method was broken down into smaller methods which could be better understand and more easily read.  Although there was no hard limit of the number of lines in the methods nor the number a methods a class could have, methods were subjectively broken down into smaller pieces based on the operations that were being performed.  For example, the AMGVending.PrintMenu() method was originally made up of all the prompt methods, which cased the PrintMenu() method to become bloated.  After breaking up the operations, it was easier to understand what the PrintMenu() method was trying to get accomplished.  In addition, every single method was commented and any strange looking operation was noted to explain the purpose.

One thing to note, not really a design thing, is that JavaDoc style comments were used.  This was because C++ doesn’t really offer a nice way to document the source code, such as JavaDocs or XML comments in C#.  JavaDocs was used as it offers a simpler and more understandable format, which many developers may already be familiar with. 

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

* Build the project using run.sh or run.bat

## Executing                                
Run the utility via the command-line from the bin directory via ./ . 

