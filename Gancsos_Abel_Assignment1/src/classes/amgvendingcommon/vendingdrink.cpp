#include "vendingdrink.h"

/**
 * This is the default constructor
 * @precondition  (There is a need for a new instance of the class)
 * @postcondition (A new instance of the object is created)
 */
VendingDrink::VendingDrink(){
}

/**
 * This is the deconstructor
 * @postcondition (The instance of the object is removed from memory)
 */
VendingDrink::~VendingDrink(){
    for(int i = 0; i < condiments.size(); i++){
        delete condiments[i];
    }
}
