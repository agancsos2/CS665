#include "amgvehicleobserver.h"

namespace amgdispatchobserver {

	int AMGVehicleObserver::GetDistance(){
		return this->distance;
	}

    /**
     * This method sorts a list of vehicles by distance
     * @param a List of vehicles to sort
	 * @param b Order
     * @return Sorted list
     * @postcondition (The list of sorted vehicles is returned)
     * @todo Change from bubble sort to merge sort
     */
    vector<AMGVehicleObserver *> AMGVehicleObserver::Sort(vector<AMGVehicleObserver *> a, AMGOrder *b){
        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < a.size(); j++){
                if(a[i]->GetVehicle()->GetDistance(b->GetShop()->GetIdentity()) + b->GetCustomer()->GetDistance(b->GetShop()->GetIdentity()) > 
					a[j]->GetVehicle()->GetDistance(b->GetShop()->GetIdentity()) + b->GetCustomer()->GetDistance(b->GetShop()->GetIdentity())){
                    AMGVehicleObserver *temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        return a;
    }
    
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
		this->delivery = nullptr;
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
                
                for(int i = 0; i < this->vehicle->GetDistances().size(); i++){
					this->vehicle->SetDistance(i, this->delivery->GetOrder()->GetCustomer()->GetDistance(i));
				}
                if(this->vehicle->GetDistance(0) == 0){
                    throw invalid_argument("Unexpected zero distance...");
                }
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
                
                if(this->delivery->GetTotalDistance() - this->distance < 0){
                    throw invalid_argument("Unexpected zero total distance...");
                }
			}	
		}
		if(this->vehicle->GetState() == VEHICLE_STATE::READY){
				cout << "** Vehicle is ready.  current distance: (";
				for(int i = 0; i < this->vehicle->GetDistances().size(); i++){
					if(i > 0){
						cout << ";";
					}
					cout  << this->vehicle->GetDistance(i);
				}
				cout << ")";
				cout << endl;
		}
    }
}
