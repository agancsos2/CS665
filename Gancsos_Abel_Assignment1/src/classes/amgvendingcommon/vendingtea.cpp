#include "vendingtea.h"

/**
 * This method checks if a sort value is valid based on name
 * @param a Name of the sort value to search for
 * @return        (The matching sort enum)
 * @precondition  (The name of the sort must be provided)
 * @postcondition (The matching sort is returned or NONE if not found)
 */
TEA_SORTS VendingTea::EnsureSortByName(string a){
    if(AMGString(a).ToLowerCase() == "black"){
        return TEA_SORTS::BLACK;
    }
    else if(AMGString(a).ToLowerCase() == "green"){
        return TEA_SORTS::GREEN;
    }
    else if(AMGString(a).ToLowerCase() == "yellow"){
        return TEA_SORTS::YELLOW;
    }
    else{
        return TEA_SORTS::NONE;
    }
}

/**
 * This method brews the drink
 * @precondition  (An instance of the class must exist)
 * @postcondition (The drink was brewed)
 */
void VendingTea::Brew(){
	cout << "Brewing drink::" << ToString() << endl;
}

/**
 * This method retrieves the possible sorts for the drink
 * @return        (Collection of sort names)
 * @postcondition (Sort names are returned)
 */
vector<string> VendingTea::GetSorts(){
    vector<string> m_final;
    m_final.push_back("None (Plain)");
    m_final.push_back("Black");
    m_final.push_back("Green");
    m_final.push_back("Yellow");
    return m_final;
}


/**
 * This is the default constructor
 * @precondition  (There is a need for a new instance of the class)
 * @postcondition (A new instance of the object is created)
 */
VendingTea::VendingTea(){
	sort = TEA_SORTS::NONE;   
}

/**
 * This is the deconstructor
 * @postcondition (The instance of the object is removed from memory)
 */
VendingTea::~VendingTea(){
    for(int i = 0; i < condiments.size(); i++){
        delete condiments[i];
    }
}

/**
 * This method returns the type of the instance
 * @return        (Type name of the instance)
 * @precondition  (The instance exists)
 * @postcondition (The type name is returned)
 */
string VendingTea::GetType(){
	return "Tea";
}

/**
 * This method returns the object as a string representation
 * @return        (A string representation of the object)
 * @precondition  (The instance exists)
 * @postcondition (The string representation of the class is returned)
 */
string VendingTea::ToString(){
    string drink_string = "(" + GetType();

    // Add the sort
    switch(sort){
        case TEA_SORTS::NONE:
            break;
        case TEA_SORTS::BLACK:
            drink_string += ";Black";
            break;
        case TEA_SORTS::GREEN:
            drink_string += ";Green";
            break;
        case TEA_SORTS::YELLOW:
            drink_string += ";Yellow";
            break;
    }

    // Add any condiments if applicable
    if(condiments.size() > 0){
        drink_string += ";";
        for(int i = 0; i < condiments.size(); i++){
            if(i > 0){
                drink_string += ",";
            }
            drink_string += condiments[i]->ToString();
        }
    }

    drink_string += ")";

    return drink_string;
}

/**
 * This method adds a new condiment to the drink
 * @precondition  (The instance exists)
 * @postcondition (The condiment is added if applicable)
 */
void VendingTea::AddCondiment(DrinkCondiment *a){
	bool found = false;
	
	// Detect if a condiment of this type has already been added
	for(int i = 0; i < condiments.size(); i++){
		if(condiments[i]->GetType() == a->GetType()){
			found = true;
		}
	}
	
	if(!found){
		condiments.push_back(a);
	}
}

/**
 * This method removes an existing condiment from the drink
 * @precondition  (The instance exists)
 * @postcondition (The condiment of the specified type is removed from the drink)
 */
void VendingTea::RemoveCondiment(DrinkCondiment *a){
	for(int i = 0; i < condiments.size(); i++){
		if(condiments[i]->GetType() == a->GetType()){
			condiments.erase(condiments.begin() + i);
		}
	}
	delete a;
}

/**
 * This method sets the sort type of the drink
 * @param a Sort type of the drink
 * @precondition  (The instance exists)
 * @postcondition (The sort type is set)
 */
void VendingTea::SetSort(TEA_SORTS a){
	sort = a;
}

/**
 * This method returns the sort type of the drink
 * @return        (Sort type of the drink)
 * @precondition  (The instance exists)
 * @postcondition (The sort type is returned)
 */
TEA_SORTS VendingTea::GetSort(){
	return sort;
}
