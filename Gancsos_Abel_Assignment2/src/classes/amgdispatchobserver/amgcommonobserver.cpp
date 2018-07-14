#include "amgcommonobserver.h"

namespace amgdispatchobserver {

	AMGDelivery *AMGCommonObserver::GetDelivery(){
		return this->delivery;
	}

	/**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGCommonObserver::AMGCommonObserver() {
	}
    
    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGCommonObserver::~AMGCommonObserver() {
	}
}
