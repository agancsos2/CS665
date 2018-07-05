#include "amgvendinghelpers.h"

/**
 * This method is displayed as a help menu for non-interactive options
 * @precondition  (Utility has been with the help switch)
 * @postcondition (Details of the utility are displayed in the system console)
 */
void AMGVendingHelpers::HelpMenu(){
    cout << AMGString("").PadLeft(80,"=") << endl;
    cout << "* Name   : AMGVending" << endl;
    cout << "* Author : Abel Gancsos" << endl;
    cout << "* Version: v. 1.0.0" << endl;
    cout << "* Flags:" << endl;
    cout << "  * -drink     : Type of drink" << endl;
    cout << "  ** Coffee" << endl;
    cout << "  ** Tea" << endl;
    cout << "  * -sort      : Subtype of the beverage" << endl;
    cout << "  ** Coffee:" << endl;
    cout << "  *** Espresso" << endl;
    cout << "  *** Americano" << endl;
    cout << "  *** Latte Macchiato" << endl;
    cout << "  ** Tea  : " << endl;
    cout << "  *** Black " << endl;
    cout << "  *** Green " << endl;
    cout << "  *** Yellow" << endl;
    cout << "  * -condiments: List of condiments to add" << endl;
    cout << "  ** Milk" << endl;
    cout << "  ** Sugar" << endl;
    cout << "  * -amount    : Quantity of the condiments to add (Max=3)" << endl;
    cout << AMGString("").PadLeft(80,"=") << endl;
}

/**
 * This method quits the program
 * @output        (Closing message)
 * @precondition  (The utiity must be running)
 * @postcondition (The program exists)
 */
void AMGVendingHelpers::ExitProgram(){
    cout << "Thank you for visiting.  Please come again soon...." << endl;
    exit(0);
}

/**
 * This method checks if a string is a digit string 
 * @param a String value to parse
 * @return        (True if all characters are integers, false if not)
 * @precondition  (A string value is provided)
 * @postcondition (Result is returned)
 * @todo          (hould be changed to lambda function)
 */
bool AMGVendingHelpers::IsDigit(string a){
	for(int i = 0; i < a.length(); i++){
		if(!isdigit(a[i])){
			return false;
		}
	}
	return true;
}

/**
 * This method validates a user input
 * @return        (True if valid, false if not)
 * @param a Input to validate
 * @param b Input type
 * @precondition  (A string input value must be provided)
 * @postcondition (Result is returned)
 */
bool AMGVendingHelpers::ValidateInput(string a, INPUT_TYPES b){
	switch(b){
		case INPUT_TYPES::STRING:
			return true;
		case INPUT_TYPES::NUMBER:
			return IsDigit(a);
		case INPUT_TYPES::BOOL:
			if(AMGString(a).ToLowerCase() == "1" ||
        		AMGString(a).ToLowerCase() == "yes" ||
        		AMGString(a).ToLowerCase() == "y"){
				return true;
			}
			else{
				return false;
			}
	}	
	return false;
}

