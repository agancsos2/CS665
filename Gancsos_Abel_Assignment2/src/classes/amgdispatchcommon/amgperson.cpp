#include "amgperson.h"

namespace amgdispatchcommon {

	/**
	 * This method sets the birthday for the object
	 * @param a Flag if object has birthday
	 * @precondition  (Instance of the object must exist)
	 * @postcondition (The birthday has been set)
	 */
	void AMGPerson::SetBirthday(bool a){
		this->birthday = a;
	}

    /**
     * This method retrieves the birthday for the object
     * @return a Flag if object has birthday
     * @precondition  (Instance of the object must exist)
     * @postcondition (The birthday has been returned)
     */
	bool AMGPerson::HasBirthday() {
		return this->birthday;
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGPerson::AMGPerson(){
		this->birthday = false;
		this->ssn = rand() % 10;
		this->first_name = "";
		this->last_name = "";
		this->age = 0;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
   	AMGPerson::~AMGPerson() {
	}

    /**
     * This is the common constructor.
     * @param first First name
     * @param last Last name
     * @param age Age
     * @postcondition (A new instance of the object has been created.)
     */
    AMGPerson::AMGPerson(string first, string last, int age) {
		this->first_name = first;
		this->last_name = last;
		this->age = age;
		this->birthday = false;
		ssn = rand() % 10;
	}

	/**
	 * This method sets the first name of the object
	 * @param first First name of the object
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The first name of the object is set)
	 */
    void AMGPerson::SetFirst(string first) {
		this->first_name = first;
	}

    /**
     * This method sets the last name of the object
     * @param last Last name of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The last name of the object is set)
     */
    void AMGPerson::SetLast(string last) {
		this->last_name = last;
	}

    /**
     * This method sets the age of the object
     * @param age Age name of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The age of the object is set)
     */
    void AMGPerson::SetAge(int age) {
		this->age = age;
	}

    /**
     * This method retrieves the first name of the object
     * @return First name of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The first name of the object is returned)
     */
    string AMGPerson::GetFirst() {
		return first_name;
	}

    /**
     * This method retrieves the last name of the object
     * @return Last name of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The last name of the object is returned)
     */
    string AMGPerson::GetLast() {
		return last_name;
	}

    /**
     * This method retrieves the age of the object
     * @return Age of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The age of the object is returned)
     */
    int AMGPerson::GetAge() {
		return age;
	}
    
}
