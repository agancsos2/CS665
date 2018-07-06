#include "drinkcondiment.h"
namespace amgvendingcommon{
    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */        
    DrinkCondiment::DrinkCondiment(){
    }

    /**
     * This is the common constructor
     * @param a Value to use for the quantity
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    DrinkCondiment::DrinkCondiment(int a){
    }

    DrinkCondiment::~DrinkCondiment(){
    }

    /**
     * This retrieves the quantity value
     * @return        (Value of the quantity property)
     * @precondition  (An instance of the class exists)
     * @postcondition (The quantity is returned)
     */
    int DrinkCondiment::GetQuantity(){
        return quantity;
    }

    /**
     * This method sets the value for the quantity
     * @param a Value to use for the quantity
     * @precondition  (An instance of the class exists)
     * @postcondition (The quantity is updated)
     */
    void DrinkCondiment::SetQuantity(int a){
        quantity = a;
    }
}
