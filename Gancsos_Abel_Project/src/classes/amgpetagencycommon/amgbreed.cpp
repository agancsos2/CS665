#include "amgbreed.h"

namespace amgpetagencycommon {

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGBreed::AMGBreed(){
		this->name = "";
        this->father_breed = shared_ptr<AMGBreed>(new AMGBreed(""));
        this->mother_breed = shared_ptr<AMGBreed>(new AMGBreed(""));
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGBreed::~AMGBreed(){
	}

    /**
     * This is the common constructor
	 * @param name Name of the breed
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGBreed::AMGBreed(string name){
		this->name = name;
	}
    
    /**
     * This method sets the father breed
	 * @param a Father breed
     * @precondition  (The instance of the object exists)
     * @postcondition (The father breed is set)
     */
	void AMGBreed::SetFatherBreed(shared_ptr<AMGBreed> a){
		father_breed = a;
	}

    /**
     * This method sets the mother breed
     * @param a Mother breed
     * @precondition  (The instance of the object exists)
     * @postcondition (The mother breed is set)
     */
    void AMGBreed::SetMotherBreed(shared_ptr<AMGBreed> a){
		mother_breed = a;
	}

    /**
     * This method gets the father breed
     * @return Father breed
     * @precondition  (The instance of the object exists)
     * @postcondition (The father breed is returned)
     */
    shared_ptr<AMGBreed> AMGBreed:: GetFatherBreed(){
		return father_breed;
	}

    /**
     * This method gets the mother breed
     * @return Mother breed
     * @precondition  (The instance of the object exists)
     * @postcondition (The mother breed is returned)
     */
    shared_ptr<AMGBreed> AMGBreed::GetMotherBreed(){
		return mother_breed;
	}

    /**
     * This method gets the name of the breed
     * @return The name of the breed
     * @precondition  (The instance of the object exists)
     * @postcondition (The name is returned)
     */
	string AMGBreed::GetName(){
		return name;
	}

    /**
     * This method returns a string representation of the object
     * @return String representation of the object
     * @precondition  (The instance of the object exists)
     * @postcondition (The string representation of the object)
     */
	string AMGBreed::ToString(){
		string breed_name = "(";
		breed_name += ("Name: " + name);
        breed_name += (";Father: " + (this->father_breed ? this->father_breed->GetName() : ""));
        breed_name += (";Mother: " + (this->mother_breed ? this->mother_breed->GetName() : ""));
		breed_name += ")";
		return breed_name;
	}
}
