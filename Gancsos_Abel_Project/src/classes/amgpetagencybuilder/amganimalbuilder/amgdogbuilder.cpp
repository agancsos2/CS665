#include "amgdogbuilder.h"

namespace amganimalbuilder {

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGDogBuilder::AMGDogBuilder(){
        this->product = shared_ptr<AMGDog>(new AMGDog());
	}

    /**
     * This is the default deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDogBuilder::~AMGDogBuilder(){
	}

    /**
     * This is the common constructor
     * @param name Name
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (A new instance of the object is created)
     */
    AMGDogBuilder::AMGDogBuilder(string name){
        this->product = shared_ptr<AMGDog>(new AMGDog());
        this->product->SetName(name);
	}

    
    /**
     * This method adds the gender for the animal in the builder
     * @param a Value for the gender
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The gender field is set)
     */
    void AMGDogBuilder::SetGender(GENDER a){
		this->product->SetGender(a);
	}

    /**
     * This method adds the owner for the animal in the builder
     * @param a Value for the owner
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The owner field is set)
     */
    void AMGDogBuilder::SetOwner(shared_ptr<AMGPerson> a){
		this->product->SetOwner(a);
	}

    /**
     * This method adds the height for the animal in the builder
     * @param a Value for the height
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The height field is set)
     */
    void AMGDogBuilder::SetHeight(float a){
		this->product->SetHeight(a);
	}

    /**
     * This method adds the weight for the animal in the builder
     * @param a Value for the weight
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The weight field is set)
     */
    void AMGDogBuilder::SetWeight(float a){
		this->product->SetWeight(a);
	}

    /**
     * This method adds the breed for the animal in the builder
     * @param a Value for the breed
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The breed field is set)
     */
    void AMGDogBuilder::SetBreed(shared_ptr<AMGBreed> a){
		this->product->SetBreed(a);
	}

    /**
     * This method spawns the new dog from the builder
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The new dog object is returned)
     * @return A new dog instance
     */
	shared_ptr<AMGAnimal> AMGDogBuilder::Build(){
        return this->product;
    }
}