#include "amglocation.h"

namespace amgbattleshipcommon {

	/**
	 * This method compares the current instance to another
	 * @param a The instance to compare to
	 * @return True if they are the same, false if not
	 * @precondition  (Both instances must exist)
	 * @postcondition (Result of the check is returned)
	 */
	bool AMGLocation::Equals(shared_ptr<AMGLocation> a){
		if(this->x_coordinates == a->x_coordinates){
			if(this->y_coordinates == a->y_coordinates){
				return true;
			}
		}
		return false;
	}

	/**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGLocation::AMGLocation(){
		this->x_coordinates = 0;
		this->y_coordinates = 0;
	}

    /**
     * This is the common constructor.
	 * @param a X coordinates
	 * @param b Y coordinates
     * @postcondition (A new instance of the object has been created.)
     */
	AMGLocation::AMGLocation(int a, int b) {
        this->x_coordinates = a;
        this->y_coordinates = b;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGLocation::~AMGLocation() {
	}

    /**
     * This method sets the value of the x coordinates
     * @param a X coordinates
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
	void AMGLocation::SetXCoordinates(int a) {
        this->x_coordinates = a;
	}

    /**
     * This method sets the value of the y coordinates
     * @param a y coordinates
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
	void AMGLocation::SetYCoordinates(int a) {
        this->y_coordinates = a;
	}

    /**
     * This method retrieves the value of the x coordinates
     * @return X coordinates
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	int AMGLocation::GetXCoordinates() {
		return this->x_coordinates;
	}

    /**
     * This method retrieves the value of the y coordinates
     * @return y coordinates
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	int AMGLocation::GetYCoordinates() {
        return this->y_coordinates;
	}

    /**
     * This method retrieves the representation of the object as a string
     * @return String representation
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	string AMGLocation::ToString() {
		string location_string = "(";
		location_string += to_string(this->x_coordinates);
		location_string += ("," + to_string(this->y_coordinates));
		location_string += ")";
		return location_string;
	}
}
