#include "amgcustomerbuilder.h"

namespace amgpersonbuilder {

    /**
	 * This method adds the gender for the person in the builder
	 * @param a Value for the gender
	 * @precondition  (The instance of the builder class must exist)
	 * @postcondition (The gender field is set)
	 */
	void AMGCustomerBuilder::SetGender(GENDER a){
		this->product->SetGender(a);
	}

    /**
     * This method adds the race for the person in the builder
     * @param a Value for the race
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The race field is set)
     */
	void AMGCustomerBuilder::SetRace(RACE a){
		this->product->SetRace(a);
	}

    /**
     * This method adds the age for the person in the builder
     * @param a Value for the age
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The age field is set)
     */
	void AMGCustomerBuilder::SetAge(int a){
		this->product->SetAge(a);
	}

    /**
     * This method adds the hair color for the person in the builder
     * @param a Value for the hair color
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The hair color field is set)
     */
	void AMGCustomerBuilder::SetHairColor(HAIR_COLOR a){
		this->product->SetHairColor(a);
	}

    /**
     * This method adds the eye color for the person in the builder
     * @param a Value for the eye color
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The hair color field is set)
     */
	void AMGCustomerBuilder::SetEyeColor(EYE_COLOR a){
		this->product->SetEyeColor(a);
	}

    /**
     * This method adds the nationality for the person in the builder
     * @param a Value for the nationality
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The nationality field is set)
     */
	void AMGCustomerBuilder::SetNationality(NATIONALITY a){
		this->product->SetNationality(a);
	}

    /**
     * This method adds the weight for the person in the builder
     * @param a Value for the weight
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The weight field is set)
     */
	void AMGCustomerBuilder::SetWeight(float a){
		this->product->SetWeight(a);
	}

    /**
     * This method adds the height for the person in the builder
     * @param a Value for the height
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The height field is set)
     */
	void AMGCustomerBuilder::SetHeight(float a){
		this->product->SetHeight(a);
	}

    /**
     * This method adds the waist size for the person in the builder
     * @param a Value for the waist size
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The waist size field is set)
     */
	void AMGCustomerBuilder::SetWaistSize(int a){
		this->product->SetWaistSize(a);
	}

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGCustomerBuilder::AMGCustomerBuilder() {
        this->product = shared_ptr<AMGPerson>(new AMGPerson());
    }

    /**
     * This is the default deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGCustomerBuilder::~AMGCustomerBuilder() {

    }

    /**
     * This is the common constructor
     * @param first First name
     * @param last Last name
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (A new instance of the object is created)
     */
    AMGCustomerBuilder::AMGCustomerBuilder(string first, string last) {
        this->product = shared_ptr<AMGPerson>(new AMGPerson());
        this->product->SetFirstName(first);
        this->product->SetLastName(last);
    }

    /**
     * This method spawns the new person from the builder
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The new person object is returned)
     * @return A new person instance
     */
	shared_ptr<AMGPerson> AMGCustomerBuilder::Build(){
        return this->product;
    }
}