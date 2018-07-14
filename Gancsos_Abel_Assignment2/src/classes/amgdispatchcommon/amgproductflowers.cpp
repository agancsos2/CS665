#include "amgproductflowers.h"

namespace amgdispatchcommon {
    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGProductFlowers::AMGProductFlowers() {
	}

    /**
     * This is the common constructor.
     * @param name Name of the object
     * @postcondition (A new instance of the object has been created.)
     */
    AMGProductFlowers::AMGProductFlowers(string name){
        this->name = name;
    }
    
    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGProductFlowers::~AMGProductFlowers() {
	}

    /**
     * This method returns the name of the object
     * @return        Name of the object
     * @precondition  (The instance exists)
     * @postcondition (The name of the object is returned)
     */
    string AMGProductFlowers::GetName() {
		return name;
	}

    /**
     * This method retrieves the type of the object
     * @return Type of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The type of the object is returned)
     */
    string AMGProductFlowers::GetType() {
		return "Flower Bouquets";
	}

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
    string AMGProductFlowers::ToString() {
		return ("(Flower Bouquets, " + name + ")");
	}
}
