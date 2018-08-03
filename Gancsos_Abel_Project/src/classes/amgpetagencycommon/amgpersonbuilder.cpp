#include "amgperson.h"

namespace amgpetagencycommon {

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGPerson::PersonBuilder::~PersonBuilder(){
    }

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
	AMGPerson::PersonBuilder::PersonBuilder() {
	}

	/**
	 * This method creates a builder object with the first and last names
	 * @param first First name of the person
	 * @param last Last name of the person
	 * @postcondition (A new instance of the builder is created)
	 */
     AMGPerson::PersonBuilder::PersonBuilder(string first, string last){
		this->first_name = first;
		this->last_name = last;	
	}

	/**
	 * This method adds the gender for the person in the builder
	 * @param a Value for the gender
	 * @precondition  (The instance of the builder class must exist)
	 * @postcondition (The gender field is set)
	 * @return The instance of the builder object with the updated fields
	 */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithGender(GENDER a){
		this->gender = a;
		return this;
	}

    /**
     * This method adds the race for the person in the builder
     * @param a Value for the race
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The race field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithRace(RACE a){
		this->race = a;
        return this;
	}

    /**
     * This method adds the age for the person in the builder
     * @param a Value for the age
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The age field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithAge(int a){
		this->age = a;
        return this;
	}

    /**
     * This method adds the hair color for the person in the builder
     * @param a Value for the hair color
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The hair color field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithHairColor(HAIR_COLOR a){
		this->hair_color = a;
        return this;
	}

    /**
     * This method adds the eye color for the person in the builder
     * @param a Value for the eye color
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The hair color field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithEyeColor(EYE_COLOR a){
		this->eye_color = a;
        return this;
	}

    /**
     * This method adds the nationality for the person in the builder
     * @param a Value for the nationality
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The nationality field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithNationality(NATIONALITY a){
		this->nationality = a;
        return this;
	}

    /**
     * This method adds the weight for the person in the builder
     * @param a Value for the weight
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The weight field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithWeight(float a){
		this->weight = a;
        return this;
	}

    /**
     * This method adds the height for the person in the builder
     * @param a Value for the height
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The height field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithHeight(float a){
		this->height = a;
        return this;
	}

    /**
     * This method adds the waist size for the person in the builder
     * @param a Value for the waist size
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The waist size field is set)
     * @return The instance of the builder object with the updated fields
     */
	AMGPerson::PersonBuilder *AMGPerson::PersonBuilder::WithWaistSize(int a){
		this->waist_size = a;
        return this;
	}

    /**
     * This method spawns the new person from the builder
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The new person object is returned)
     * @return A new person instance
     */
	shared_ptr<AMGPerson> AMGPerson::PersonBuilder::Build(){
        return shared_ptr<AMGPerson>(new AMGPerson(this));
    }

}
