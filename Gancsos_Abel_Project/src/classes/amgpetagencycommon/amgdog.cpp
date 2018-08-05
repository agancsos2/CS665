#include "amgdog.h"

namespace amgpetagencycommon {

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
    string AMGDog::ToString(){
		string dog_string = "(";
		dog_string += ("Name: " + this->GetName());
		dog_string += (";Owner: ");
		if(this->GetOwner() != shared_ptr<AMGPerson>(nullptr)){
			dog_string += (this->GetOwner()->GetFirstName() + " " + this->GetOwner()->GetLastName());
		}
		dog_string += (";" + AMGCommonEnums::GetGenderName(this->GetGender()));
		dog_string += (";Height: " + to_string(this->GetHeight()));
		dog_string += (";Weight: " + to_string(this->GetWeight()));
		dog_string += (";Breed: " + this->GetBreed()->ToString());
		dog_string += ")";
		return dog_string;
	}

    AMGDog::AMGDog() {
        this->name = "";
        this->height = 0.0;
        this->weight = 0.0;
        this->gender = GENDER::NONE;
        this->breed = shared_ptr<AMGBreed>(new AMGBreed("NONE"));
        this->owner = shared_ptr<AMGPerson>(nullptr);
    }

	/**
	 * This method sets the owner (adopts) the animal
	 * @param a Person to set as owner
	 * @precondition  (The instance of the animal must exist without an owner)
	 * @postcondition (The animal is adopted)
	 */
	void AMGDog::Adopt(shared_ptr<AMGPerson> a, bool delay = true){
		if(this->GetOwner() == nullptr || !a){
			if(delay){
				cout << "Adopting..." << endl;
				AMGSystem::Sleeper(adoption_time_seconds);
				cout << "Adopted! Please give " << this->GetName() << " a good home." << endl;
			}
		    this->owner = a;
 		}
		else{
			cout << "Animal already has an owner...." << endl;
		}
	}

    void AMGDog::SetName(string a) {
        this->name = a;
    }

	/**
	 * This method returns the type of the animal
	 * @return Name of the animal type
	 * @precondition  (An instance of the class exists)
	 * @postcondition (The name of the animal type is returned)
	 */
    string AMGDog::GetType(){
		return "Dog";
	}

	/**
     * This method retrieves the gender
     * @return Gender
     * @precondition  (The instance of the object must exist)
     * @postcondition (THe property is returned)
     */
    GENDER AMGDog::GetGender() {
        return this->gender;
    }

    /**
     * This method retrieves the name
     * @return Name
     * @precondition  (The instance of the object must exist)
     * @postcondition (THe property is returned)
     */
    string AMGDog::GetName() {
        return this->name;
    }

    /**
     * This method retrieves the height
     * @return Height
     * @precondition  (The instance of the object must exist)
     * @postcondition (THe property is returned)
     */
    float AMGDog::GetHeight() {
        return this->height;
    }

    /**
     * This method retrieves the Weight
     * @return Weight
     * @precondition  (The instance of the object must exist)
     * @postcondition (THe property is returned)
     */
    float AMGDog::GetWeight() {
        return this->weight;
    }

    /**
     * This method retrieves the owner
     * @return Owner
     * @precondition  (The instance of the object must exist)
     * @postcondition (THe property is returned)
     */
    shared_ptr<AMGPerson> AMGDog::GetOwner() {
        return this->owner;
    }

    /**
     * This method retrieves the breed
     * @return Breeds
     * @precondition  (The instance of the object must exist)
     * @postcondition (THe property is returned)
     */
    shared_ptr<AMGBreed> AMGDog::GetBreed() {
        return this->breed;
    }

	/**
     * This method adds the gender for the animal in the builder
     * @param a Value for the gender
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The gender field is set)
     */
    void AMGDog::SetGender(GENDER a){
		this->gender = a;
	}

    /**
     * This method adds the owner for the animal in the builder
     * @param a Value for the owner
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The owner field is set)
     */
    void AMGDog::SetOwner(shared_ptr<AMGPerson> a){
		this->owner = a;
	}

    /**
     * This method adds the height for the animal in the builder
     * @param a Value for the height
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The height field is set)
     */
    void AMGDog::SetHeight(float a){
		this->height = a;
	}

    /**
     * This method adds the weight for the animal in the builder
     * @param a Value for the weight
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The weight field is set)
     */
    void AMGDog::SetWeight(float a){
		this->weight = a;
	}

    /**
     * This method adds the breed for the animal in the builder
     * @param a Value for the breed
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The breed field is set)
     */
    void AMGDog::SetBreed(shared_ptr<AMGBreed> a){
        this->breed = a;
	}
}
