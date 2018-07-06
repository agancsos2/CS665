#include "vendingcoffee.h"
namespace amgvendingcommon{
    /**
     * This method checks if a sort value is valid based on name
     * @param a Name of the sort value to search for
     * @return        (The matching sort enum)
     * @precondition  (The name of the sort must be provided)
     * @postcondition (The matching sort is returned or NONE if not found)
     */
    COFFEE_SORTS VendingCoffee::EnsureSortByName(string a){
        if(AMGString(a).ToLowerCase() == "espresso"){
            return COFFEE_SORTS::ESPRESSO;
        }
        else if(AMGString(a).ToLowerCase() == "americano"){
            return COFFEE_SORTS::AMERICANO;
        }
        else if(AMGString(a).ToLowerCase() == "latte macchiato"){
            return COFFEE_SORTS::LATTE_MACCHIATO;
        }
        else{
            return COFFEE_SORTS::NONE;
        }
    }

	/**
	 * This method adds the condiments to the drink
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The condiments are added into the drink)
	 */
	void VendingCoffee::AddCondiments(){
		cout << "Adding condiments into drink::" << ToString() << endl;
		for(int i = 0; i < condiments.size(); i++){
            #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
                Sleep(2 * 100);
            #else
                sleep(2);
            #endif
			cout << "Added condiment::" << condiments[i]->ToString() << endl;
		}
	}

    /**
     * This method brews the drink
     * @precondition  (An instance of the class must exist)
     * @postcondition (The drink was brewed)
     */
    void VendingCoffee::Brew(){
        cout << "Brewing drink::" << ToString() << endl;
		#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
			Sleep(brew_time_seconds * 100);
		#else
			sleep(brew_time_seconds);
		#endif
		if(condiments.size() > 0){
			AddCondiments();
		}
    }

    /**
     * This method retrieves the possible sorts for the drink
     * @return        (Collection of sort names)
     * @postcondition (Sort names are returned)
     */
    vector<string> VendingCoffee::GetSorts(){
        vector<string> m_final;
        m_final.push_back("None (Plain)");
        m_final.push_back("Espresso");
        m_final.push_back("Americano");
        m_final.push_back("Latte Macchiato");
        return m_final;
    }

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    VendingCoffee::VendingCoffee(){
        sort = COFFEE_SORTS::NONE;   
		brew_time_seconds = 10;
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    VendingCoffee::~VendingCoffee(){
    }

    /**
     * This method returns the type of the instance
     * @return        (Type name of the instance)
     * @precondition  (The instance exists)
     * @postcondition (The type name is returned)
     */
    string VendingCoffee::GetType(){
        return "Coffee";
    }

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
    string VendingCoffee::ToString(){
        string drink_string = "(" + GetType();

        // Add the sort
        switch(sort){
            case COFFEE_SORTS::NONE:
                break;
            case COFFEE_SORTS::ESPRESSO:
                drink_string += ";Type: Espresso";
                break;
            case COFFEE_SORTS::AMERICANO:
                drink_string += ";Type: Americano";
                break;
            case COFFEE_SORTS::LATTE_MACCHIATO:
                drink_string += ";Type: Latte Macchiato";
                break;	
        }

        // Add any condiments if applicable
        if(condiments.size() > 0){
            drink_string += ";Condiments: ";
            for(int i = 0; i < condiments.size(); i++){
                if(i > 0){
                    drink_string += ",";
                }
                drink_string += condiments.at(i)->ToString();
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
    void VendingCoffee::AddCondiment(DrinkCondiment *a){
        bool found = false;

        if(a->GetQuantity() > 0){
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
    }

    /**
     * This method removes an existing condiment from the drink
     * @precondition  (The instance exists)
     * @postcondition (The condiment of the specified type is removed from the drink)
     */
    void VendingCoffee::RemoveCondiment(DrinkCondiment *a){
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
    void VendingCoffee::SetSort(COFFEE_SORTS a){
        sort = a;
    }

    /**
     * This method returns the sort type of the drink
     * @return        (Sort type of the drink)
     * @precondition  (The instance exists)
     * @postcondition (The sort type is returned)
     */
    COFFEE_SORTS VendingCoffee::GetSort(){
        return sort;
    }
}
