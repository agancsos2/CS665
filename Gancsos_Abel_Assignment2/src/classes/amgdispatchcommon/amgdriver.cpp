#include "amgdriver.h"

namespace amgdispatchcommon {

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGDriver::AMGDriver() {
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDriver::~AMGDriver() {
	}

    /**
     * This method retrieves the type of the object
     * @return Type of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The type of the object is returned)
     */
    string AMGDriver::GetType() {
		return "Driver";
	}

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
	string AMGDriver::ToString() {
		string person_string = "(";
		person_string += ("SSN: " + ssn);
		person_string += (";First Name: " + first_name);
		person_string += (";Last Name: " + last_name);
		person_string += (";Age: " + to_string(age));
		person_string += ")";
		return person_string;
	}    
}
