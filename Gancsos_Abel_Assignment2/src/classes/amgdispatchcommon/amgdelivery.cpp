#include "amgdelivery.h"

namespace amgdispatchcommon{

    /**
     * This method sets the distnace of the object
     * @param distnace Total distance of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The total distance of the object is set)
     */
	void AMGDelivery::SetTotalDistance(int distance) {
		this->total_distance = distance;
	}

    /**
     * This method retrieves the total distnace of the object
     * @return Total distance of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The total distance of the object is returned)
     */
    int AMGDelivery::GetTotalDistance() {
		return this->total_distance;
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGDelivery::AMGDelivery(){
		this->total_distance = 0;
		this->delivery_id = rand();
		this->order = new AMGOrder();
	}
	
    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDelivery::~AMGDelivery() {
        delete order;
	}

    /**
     * This is the common constructor.
     * @param order Order item that the delivery instance includes
     * @postcondition (A new instance of the object has been created.)
     */
    AMGDelivery::AMGDelivery(AMGOrder *order, int distance) {
		this->order = order;
		this->total_distance = distance;
		this->delivery_id = rand();
	}   

    /**
     * This method sets the order of the object
     * @param order Order of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The order of the object is set)
     */
	void AMGDelivery::SetOrder(AMGOrder *order) {
		this->order = order;
	}

    /**
     * This method retrieves the order of the object
     * @return Order of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The order of the object is returned)
     */
	AMGOrder *AMGDelivery::GetOrder(){
		return order;
	}
    
    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
    string AMGDelivery::ToString(){
		string delivery_string = "(";
		delivery_string += ("Delivery ID: " + to_string(delivery_id));
		delivery_string += (";Order: " + order->ToString());
		delivery_string += ")";
		return delivery_string;        
    }
}
