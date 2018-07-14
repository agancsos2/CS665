#include "amgvehicleobserver.h"

namespace amgdispatchobserver {

    /**
     * This method sets the delivery object for dispatch purposes
     * @param a Delivery
     * @precondition  (The instance of the object must exist)
     * @postcondition (The delivery is set)
     */
	void AMGVehicleObserver::SetDelivery(AMGDelivery *a){
		if(this->delivery == nullptr){
			cout << "Notifying driver of " << this->vehicle->GetName() << " they have a new delivery..." << endl;
			AMGSystem::Sleep(notify_delay_seconds);
		}
		this->delivery = a;
		if(a){
			this->vehicle->SetState(VEHICLE_STATE::IN_TRANSIT);
		}
	}

	AMGDelivery *AMGVehicleObserver::GetDelivery(){
		return this->delivery;
	}

    /**
     * This method retrieves the vehicle object for dispatch purposes
     * @return Vehicle
     * @precondition  (The instance of the object must exist)
     * @postcondition (The vehicle is returned)
     */
	AMGVehicle *AMGVehicleObserver::GetVehicle(){
		return this->vehicle;
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGVehicleObserver::AMGVehicleObserver() {
		this->delivery = new AMGDelivery();
		this->vehicle = new AMGVehicle();
		this->distance = 0;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGVehicleObserver::~AMGVehicleObserver() {
		if(vehicle){
			delete vehicle;
		}
	}

    /**
     * This is the common constructor.
     * @param a Vehicle object for the observer
     * @postcondition (A new instance of the object has been created.)
     */
    AMGVehicleObserver::AMGVehicleObserver(AMGVehicle *a) {
		this->vehicle = a;
		this->delivery = nullptr;
		this->distance = 0;
	}
    
    /**
     * This method updates the object with the latest information
     * @param delivery Delivery
     * @param distance Distance
     * @precondition  (The instance of the object must exist)
     * @postcondition (The object is updated)
     */
    void AMGVehicleObserver::Update(int distance) {
		if(this->delivery == nullptr){
			if(delivery){
				this->vehicle->SetState(VEHICLE_STATE::IN_TRANSIT);
			}
		}
        else {
			if((this->distance + distance) >= this->delivery->GetTotalDistance()) {
				this->distance = 0;
				this->vehicle->SetDistance(this->delivery->GetOrder()->GetCustomer()->GetDistance());
				this->delivery->GetOrder()->SetState(ORDER_STATE::DELIVERED);
				this->vehicle->SetState(VEHICLE_STATE::READY);
				this->delivery = nullptr;
			}
			else {
				this->distance += distance;
			}
		}
    }
    
    /**
     * This method displays the latest information in the observer
     * @precondition  (The instance of the object must exist)
     * @postcondition (The object is updated)
     */
    void AMGVehicleObserver::Display() {
        cout << "* Vehicle: " << this->vehicle->GetName();
		cout << (this->vehicle->HasFreezer() ? " (Freezer)" : " (No Freezer)") << endl;
		cout << "** Delivery:" << endl;
		if(this->delivery != NULL){
			cout << "*** Customer: " << this->delivery->GetOrder()->GetCustomer()->ToString() << endl;
			cout << "*** Items:" << endl;
			for(AMGItem *cursor : this->delivery->GetOrder()->GetItems()){
				cout << "**** " << cursor->ToString() << endl;
			}
			if(this->vehicle->GetState() == VEHICLE_STATE::IN_TRANSIT){
				cout << "** Miles Travelled: " << this->distance << endl;
				cout << "** Miles Left     : " << this->delivery->GetTotalDistance() - this->distance << endl;
			}	
		}
		if(this->vehicle->GetState() == VEHICLE_STATE::READY){
				cout << "** Vehicle is ready.  current distance: " << this->vehicle->GetDistance() << endl;
		}
    }
}
