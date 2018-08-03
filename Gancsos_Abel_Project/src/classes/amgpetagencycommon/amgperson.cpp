#include "amgperson.h"

namespace amgpetagencycommon {
    
    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
	AMGPerson::AMGPerson(){
    	first_name = "";
        last_name = "";
        gender = GENDER::NONE;
        race = RACE::NONE;
        age = 0;
        hair_color = HAIR_COLOR::NONE;
        eye_color = EYE_COLOR::NONE;
        nationality = NATIONALITY::NONE;
        weight = 0.0;
        height = 0.0;
        waist_size = 0; 
	}
    
    /**
     * This method is used to return the first name
     * @return First name
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The first name is returned)
     */
    string AMGPerson::GetFirstName(){
        return this->first_name;
    }
    
    /**
     * This method is used to return the last name
     * @return Last name
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    string AMGPerson::GetLastName(){
        return this->last_name;
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGPerson::~AMGPerson() {
	}

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
	string AMGPerson::ToString() {
		string person_string = "(";
		person_string += ("First: " + first_name); 
		person_string += (";Last: " + last_name);
		person_string += (";" + AMGCommonEnums::GetGenderName(this->gender));
		person_string += (";RACE: " + AMGCommonEnums::GetRaceName(this->race));
        person_string += (";Age: " + to_string(age));
		person_string += (";Hair: " + AMGCommonEnums::GetHairColorName(this->hair_color));
		person_string += (";Eyes: " + AMGCommonEnums::GetEyeColorName(this->eye_color));
		person_string += (";Nationality: " + AMGCommonEnums::GetNationalityName(this->nationality));
		person_string += (";Weight: " + to_string(weight) + " lb");
        person_string += (";Height: " + to_string(height) + " in");
        person_string += (";Waist Size: " + to_string(waist_size));
		person_string += ")";
		return person_string;
	}

    /**
     * This is the builder constructor
     * @param builder Builder instance containing the person information
     * @postcondition (A new person instance is created from the builder)
     */
	AMGPerson::AMGPerson(AMGPerson::PersonBuilder *builder) {
		this->first_name = builder->first_name;
        this->last_name = builder->last_name;
        this->gender = builder->gender;
        this->race = builder->race;
        this->age = builder->age;
        this->hair_color = builder->hair_color;
        this->eye_color = builder->eye_color;
        this->nationality = builder->nationality;
        this->weight = builder->weight;
        this->height = builder->height;
        this->waist_size = builder->waist_size;
        delete builder;
	}
}
