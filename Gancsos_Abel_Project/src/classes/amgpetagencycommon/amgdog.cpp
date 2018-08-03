#include "amgdog.h"

namespace amgpetagencycommon {

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
	AMGDog::AMGDog(){
    	gender = GENDER::NONE;
        name = "";
        height = 0.0;
        weight = 0.0;
        breed = shared_ptr<AMGBreed>(new AMGBreed());
		owner = nullptr;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDog::~AMGDog(){
	}

    /**
     * This method returns the breed of the animal
     * @return Breed of the animal
     * @precondition  (An instance of the class exists)
     * @postcondition (The breed of the animal type is returned)
     */
   	shared_ptr<AMGBreed> AMGDog::GetBreed(){
		return breed;
	}

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
    string AMGDog::ToString(){
		string dog_string = "(";
		dog_string += ("Name: " + name);
		dog_string += (";Owner: ");
		if(owner != shared_ptr<AMGPerson>(nullptr)){
			dog_string += (owner->GetFirstName() + " " + owner->GetLastName());
		}
		dog_string += (";" + AMGCommonEnums::GetGenderName(this->gender));
		dog_string += (";Height: " + to_string(height));
		dog_string += (";Weight: " + to_string(weight));
		dog_string += (";Breed: " + breed->ToString()); 
		dog_string += ")";
		return dog_string;
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
     * This is the builder constructor
     * @param builder Builder instance containing the person information
     * @postcondition (A new person instance is created from the builder)
     */
    AMGDog::AMGDog(shared_ptr<DogBuilder> a){
		this->owner = nullptr;
        this->gender = a->gender;
        this->name = a->name;
        this->height = a->height;
        this->weight = a->weight;
        this->breed = a->breed;
	}

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGDog::DogBuilder::DogBuilder(){
		this->owner = nullptr;
        this->gender = GENDER::NONE;
        this->name = "";
        this->height = 0.0;
        this->weight = 0.0;
        this->breed = shared_ptr<AMGBreed>(new AMGBreed());
	}

	/**
	 * This method sets the owner (adopts) the animal
	 * @param a Person to set as owner
	 * @precondition  (The instance of the animal must exist without an owner)
	 * @postcondition (The animal is adopted)
	 */
	void AMGDog::Adopt(shared_ptr<AMGPerson> a, bool delay = true){
		if(this->owner == nullptr || !a){
			if(delay){
				cout << "Adopting..." << endl;
				AMGSystem::Sleep(adoption_time_seconds);
				cout << "Adopted! Please give " << name << " a good home." << endl;
			}
			this->owner = a;
		}
		else{
			cout << "Animal already has an owner...." << endl;
		}
	}

    /**
     * This is the default deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDog::DogBuilder::~DogBuilder(){
	}

    /**
     * This method adds the name for the animal in the builder
     * @param a Value for the name
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The name field is set)
     * @return The instance of the builder object with the updated fields
     */
    AMGDog::DogBuilder::DogBuilder(string name){
		this->name = name;
		this->breed = shared_ptr<AMGBreed>(new AMGBreed());
	}

    /**
     * This method adds the gender for the animal in the builder
     * @param a Value for the gender
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The gender field is set)
     * @return The instance of the builder object with the updated fields
     */
    AMGDog::DogBuilder *AMGDog::DogBuilder::WithGender(GENDER a){
		this->gender = a;
        return this;
	}

    /**
     * This method adds the height for the animal in the builder
     * @param a Value for the height
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The height field is set)
     * @return The instance of the builder object with the updated fields
     */
    AMGDog::DogBuilder *AMGDog::DogBuilder::WithHeight(float a){
		this->height = a;
        return this;
	}

    /**
     * This method adds the weight for the animal in the builder
     * @param a Value for the weight
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The weight field is set)
     * @return The instance of the builder object with the updated fields
     */
    AMGDog::DogBuilder *AMGDog::DogBuilder::WithWeight(float a){
		this->weight = a;
        return this;
	}

    /**
     * This method adds the breed for the animal in the builder
     * @param a Value for the breed
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The breed field is set)
     * @return The instance of the builder object with the updated fields
     */
    AMGDog::DogBuilder *AMGDog::DogBuilder::WithBreed(shared_ptr<AMGBreed> a){
        this->breed = a;
        return this;
	}
    
    /**
     * This method spawns the new dog from the builder
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The new dog object is returned)
     * @return A new dog instance
     */
    shared_ptr<AMGDog> AMGDog::DogBuilder::Build() {
        return shared_ptr<AMGDog>(new AMGDog(shared_ptr<DogBuilder>(this)));
    }
}
