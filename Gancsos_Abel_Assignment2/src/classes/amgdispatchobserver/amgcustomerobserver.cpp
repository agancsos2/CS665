#include "amgcustomerobserver.h"

namespace amgdispatchobserver {

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGCustomerObserver::AMGCustomerObserver() {
		this->customer = shared_ptr<AMGCustomer>(new AMGCustomer());
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGCustomerObserver::~AMGCustomerObserver() {
	}

    /**
     * This is the common constructor.
     * @param a Customer object for the observer
     * @postcondition (A new instance of the object has been created.)
     */
    AMGCustomerObserver::AMGCustomerObserver(shared_ptr<AMGCustomer> a) {
		this->customer = a;
	}
    
    /**
     * This method updates the object with the latest information
     * @param delivery Delivery
     * @param distance Distance
     * @precondition  (The instance of the object must exist)
     * @postcondition (The object is updated)
     */
    void AMGCustomerObserver::Update(shared_ptr<AMGDelivery> delivery, int distance) {
        if(this->delivery == nullptr){
			this->delivery = delivery;
            cout << "Notifying customer that they have a new scheduled delivery..." << endl;
            AMGSystem::Sleep(notify_delay_seconds);
        }
        
    }
    
    /**
     * This method displays the latest information in the observer
     * @precondition  (The instance of the object must exist)
     * @postcondition (The object is updated)
     */
    void AMGCustomerObserver::Display() {
        
    }
}

