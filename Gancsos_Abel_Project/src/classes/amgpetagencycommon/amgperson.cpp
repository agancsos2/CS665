#include "amgperson.h"

namespace amgpetagencycommon {
    
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

    AMGPerson::AMGPerson() {
        this->first_name = "";
        this->last_name = "";
        this->age = 0;
        this->waist_size = 0.0;
        this->height = 0.0;
        this->weight = 0.0;
        this->gender = GENDER::NONE;
        this->race = RACE::NONE;
        this->nationality = NATIONALITY::NONE;
        this->eye_color = EYE_COLOR::NONE;
        this->hair_color = HAIR_COLOR::NONE;
    }

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
	string AMGPerson::ToString() {
		string person_string = "(";
		person_string += ("First: " + this->GetFirstName()); 
		person_string += (";Last: " + this->GetLastName());
		person_string += (";" + AMGCommonEnums::GetGenderName(this->GetGender()));
		person_string += (";RACE: " + AMGCommonEnums::GetRaceName(this->GetRace()));
        person_string += (";Age: " + to_string(this->GetAge()));
		person_string += (";Hair: " + AMGCommonEnums::GetHairColorName(this->GetHairColor()));
		person_string += (";Eyes: " + AMGCommonEnums::GetEyeColorName(this->GetEyeColor()));
		person_string += (";Nationality: " + AMGCommonEnums::GetNationalityName(this->GetNationality()));
		person_string += (";Weight: " + to_string(this->GetWeight()) + " lb");
        person_string += (";Height: " + to_string(this->GetHeight()) + " in");
        person_string += (";Waist Size: " + to_string(this->GetWaistSize()));
		person_string += ")";
		return person_string;
	}

    /**
     * This method is used to return the gender
     * @return Gender
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    GENDER AMGPerson::GetGender() {
        return this->gender;
    }

    /**
     * This method is used to return the race
     * @return Race
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    RACE AMGPerson::GetRace() {
        return this->race;
    }

    /**
     * This method is used to return the age
     * @return Age
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    int AMGPerson::GetAge() {
        return this->age;
    }

    /**
     * This method is used to return the hair color
     * @return Hair color
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    HAIR_COLOR AMGPerson::GetHairColor() {
        return this->hair_color;
    }

    /**
     * This method is used to return the eye color
     * @return Eye color
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    EYE_COLOR AMGPerson::GetEyeColor() {
        return this->eye_color;
    }

    /**
     * This method is used to return the nationality
     * @return Nationality
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    NATIONALITY AMGPerson::GetNationality() {
        return this->nationality;
    }

    /**
     * This method is used to return the weight
     * @return Weight
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    float AMGPerson::GetWeight() {
        return this->weight;
    }

    /**
     * This method is used to return the height
     * @return Height
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    float AMGPerson::GetHeight() {
        return this->height;
    }

    /**
     * This method is used to return the wasit size
     * @return Waist size
     * @precondotion  (The instance of the object must exist)
     * @postcondition (The last name is returned)
     */
    int AMGPerson::GetWaistSize() {
        return this->waist_size;
    }

    /**
	 * This method adds the gender for the person in the builder
	 * @param a Value for the gender
	 * @precondition  (The instance of the builder class must exist)
	 * @postcondition (The gender field is set)
	 */
	void AMGPerson::SetGender(GENDER a){
		this->gender = a;
	}

    /**
     * This method adds the race for the person in the builder
     * @param a Value for the race
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The race field is set)
     */
	void AMGPerson::SetRace(RACE a){
		this->race = a;
	}

    /**
     * This method adds the age for the person in the builder
     * @param a Value for the age
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The age field is set)
     */
	void AMGPerson::SetAge(int a){
		this->age = a;
	}

    /**
     * This method adds the hair color for the person in the builder
     * @param a Value for the hair color
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The hair color field is set)
     */
	void AMGPerson::SetHairColor(HAIR_COLOR a){
		this->hair_color = a;
	}

    /**
     * This method adds the eye color for the person in the builder
     * @param a Value for the eye color
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The hair color field is set)
     */
	void AMGPerson::SetEyeColor(EYE_COLOR a){
		this->eye_color = a;
	}

    /**
     * This method adds the nationality for the person in the builder
     * @param a Value for the nationality
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The nationality field is set)
     */
	void AMGPerson::SetNationality(NATIONALITY a){
		this->nationality = a;
	}

    /**
     * This method adds the weight for the person in the builder
     * @param a Value for the weight
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The weight field is set)
     */
	void AMGPerson::SetWeight(float a){
		this->weight = a;
	}

    /**
     * This method adds the height for the person in the builder
     * @param a Value for the height
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The height field is set)
     */
	void AMGPerson::SetHeight(float a){
		this->height = a;
	}

    /**
     * This method adds the waist size for the person in the builder
     * @param a Value for the waist size
     * @precondition  (The instance of the builder class must exist)
     * @postcondition (The waist size field is set)
     */
	void AMGPerson::SetWaistSize(int a){
		this->waist_size = a;
	}

    void AMGPerson::SetFirstName(string a) {
        this->first_name = a;
    }

    void AMGPerson::SetLastName(string a) {
        this->last_name = a;
    }
}
