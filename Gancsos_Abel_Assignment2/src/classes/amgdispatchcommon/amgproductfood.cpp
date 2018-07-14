#include "amgproductfood.h"

namespace amgdispatchcommon {

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGProductFood::AMGProductFood() {
		this->food_type = FOOD_TYPE::NONE;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGProductFood::~AMGProductFood() {
	}

    /**
     * This is the common constructor.
     * @param name Name of the product
     * @param type Type of the food
     * @postcondition (A new instance of the object has been created.)
     */
    AMGProductFood::AMGProductFood(string name, FOOD_TYPE type) {
		this->name = name;
		this->food_type = type;
	}

    /**
     * This method retrieves the type of the object
     * @return Type of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The type of the object is returned)
     */
    string AMGProductFood::GetType() {
		return "Food";
	}

    /**
     * This method returns the name of the object
     * @return        Name of the object
     * @precondition  (The instance exists)
     * @postcondition (The name of the object is returned)
     */
    string AMGProductFood::GetName() {
		return name;
	}

    /**
     * This method retrieves the food type of the object
     * @return Food type of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The food type of the object is returned)
     */
    FOOD_TYPE AMGProductFood::GetFoodType() {
		return food_type;
	}

    /**
     * This method sets the name of the object
     * @param name Name of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The name of the object is set)
     */
    void AMGProductFood::SetName(string name) {
		this->name = name;
	}

    /**
     * This method sets the food type of the object
     * @param type Food type of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The food type of the object is set)
     */
    void AMGProductFood::SetFoodType(FOOD_TYPE type) {
		this->food_type = type;
	}
	
    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
	string AMGProductFood::ToString(){
		string food_string = "(";
		food_string += ("Food;");
		food_string += (";Name: " + name);
		switch(food_type){
			case FOOD_TYPE::HOT:
				food_string += ("; Hot");
				break;
			case FOOD_TYPE::COLD:
				food_string += ("; Cold");
				break;
			default:
				break;
		}
		food_string += ")";
		return food_string;
	}
}
