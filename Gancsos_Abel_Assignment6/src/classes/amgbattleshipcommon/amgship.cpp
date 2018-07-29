#include "amgship.h"

namespace amgbattleshipcommon {

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGShip::AMGShip(){
	}

    /**
     * This is the common constructor.
	 * @param a X coordinates
	 * @param b Y coordinates
     * @postcondition (A new instance of the object has been created.)
     */
	AMGShip::AMGShip(int a, int b) {
		this->location.push_back(shared_ptr<AMGLocation>(new AMGLocation(a,b)));
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGShip::~AMGShip() {
	}

	/**
	 * This method adds a location to the local collection
	 * @param a Location
	 * @precondition  (The instance of the object must exist)
     * @postcondition (The location was added)
     */
	void AMGShip::AddLocation(shared_ptr<AMGLocation> a) {
		this->location.push_back(a);
	}

    /**
     * This method removes a location from the local collection
     * @param a Location
     * @precondition  (The instance of the object must exist)
     * @postcondition (The location was removed)
     */
	void AMGShip::RemoveLocation(shared_ptr<AMGLocation> a){
		for(int i = 0; i < this->location.size(); i++){
			if(this->location[i]->Equals(a)){
				this->location.erase(this->location.begin() + i);
			}
		}
	}

    /**
     * This method retrieves the value of the locations
     * @return Location
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	vector<shared_ptr<AMGLocation> > AMGShip::GetLocation() {
		return this->location;
	}

    /**
     * This method retrieves the representation of the object as a string
     * @return String representation
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	string AMGShip::ToString() {
		string ship_string = "";
		return ship_string;
	}
}
