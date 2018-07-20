#include "amgshop.h"

namespace amgdispatchcommon {

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGShop::AMGShop() {
        this->identity = rand();
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGShop::~AMGShop() {
        for(int i = 0; i < products.size(); i++){
            delete products[i];
        }
	}

    /**
     * This is the common constructor.
     * @param name Name of the store
	 * @param distance Distance of the store
	 * @param products Products available at the store
     * @postcondition (A new instance of the object has been created.)
     */
    AMGShop::AMGShop(string name, int distance, vector<AMGProduct *> products) {
		this->name = name;
        this->identity = rand();
		this->distance = distance;
		this->products = products;
	}

	/**
	 * This method retrieves the name of the object
	 * @return Name of the object
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The name of the object is returned)
	 */
   	string AMGShop::GetName() {
		return name;
	}
    
    /**
     * This method sets the ID of the object
     * @param a ID of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The id of the object is set)
     */
    void AMGShop::SetIdentity(int a) {
        this->identity = a;
    }
    
    /**
     * This method retrieves the id of the object
     * @return ID of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The ID of the object is returned)
     */
    int AMGShop::GetIdentity() {
        return this->identity;
    }

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
    string AMGShop::ToString() {
		string shop_string = "(";
		shop_string += ("Name: " + name);
		shop_string += (";Distance: " + to_string(distance));
		shop_string += (";Products: ");
		for(int i = 0; i < products.size(); i++){
			if(i > 0){
				shop_string += ",";
			}
			shop_string += products[i]->ToString();
		}
		shop_string += ")";
		return shop_string;
	}

    /**
     * This method retrieves the products of the object
     * @return Products of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The products of the object is returned)
     */
    vector<AMGProduct *> AMGShop::GetProducts() {
		return products;
	}

    /**
     * This method retrieves the distance of the object
     * @return Distance of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distance of the object is returned)
     */
    int AMGShop::GetDistance() {
		return distance;
	}
}
