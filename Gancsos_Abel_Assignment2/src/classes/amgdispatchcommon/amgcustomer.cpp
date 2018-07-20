#include "amgcustomer.h"

namespace amgdispatchcommon {

	/**
     * This method adds a distance to the collection
     * @param a Distance 
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distance is added)
     */
	void AMGCustomer::AddDistance(int a) {
	}

    /**
     * This method retrieves the distance of the object
	 * @param a Store index
     * @return Distance of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distance of the object is returned)
     */
    int AMGCustomer::GetDistance(int a) {
		return distances[a];
	}
    
    /**
     * This method retrieves the distances for the state
     * @return Distances of the state
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distances of the state is returned)
     */
    vector<int> AMGCustomer::GetDistances(){
        return this->distances;
    }

    /**
     * This method removes a distance from the collection
     * @param a Store index
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distance is removed)
     */
    void AMGCustomer::RemoveDistance(int a) {
		this->distances.erase(this->distances.begin() + a);
	}

    /**
     * This method sets the distance of the object
     * @param a Distance
	 * @param b Store index
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distance of the object is set)
     */
    void AMGCustomer::SetDistance(int a, int b) {
     	this->distances[a] = b;
    }

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGCustomer::AMGCustomer() {
        this->distances.push_back(0);
	}

    /**
     * This is the common constructor.
     * @param first First name
     * @param last Last name
     * @param age Age
     * @postcondition (A new instance of the object has been created.)
     */
    AMGCustomer::AMGCustomer(string first, string last, int age) {
        this->first_name = first;
        this->last_name = last;
        this->age = age;
        this->birthday = false;
        this->distances.push_back(0);
		this->ssn = "";
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGCustomer::~AMGCustomer() {
	}

    /**
     * This method retrieves the type of the object
     * @return Type of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The type of the object is returned)
     */
    string AMGCustomer::GetType() {
		return "Customer";
	}

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
	string AMGCustomer::ToString() {
		string person_string = "(";
		person_string += ("SSN: " + ssn);
		person_string += (";First Name: " + first_name);
		person_string += (";Last Name: " + last_name);
		person_string += (";Age: " + to_string(age));
		person_string += ")";
		return person_string;
	}    

    /**
     * This is the common constructor.
	 * @param a Distance of the customer
     * @postcondition (A new instance of the object has been created.)
     */
    AMGCustomer::AMGCustomer(int a){
        this->distances.push_back(a);
	}
    
}
