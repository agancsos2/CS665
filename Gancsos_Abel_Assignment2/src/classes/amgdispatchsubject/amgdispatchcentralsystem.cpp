#include "amgdispatchcentralsystem.h"

namespace amgdispatchsubject {

	/**
	 * This method checks if all deliveries were delivered
	 * @return True if yes, false if no
	 * @precondition  (The instance of the object must exist)
     * @postcondition (The result of the lookup is returned)
	 */
	bool AMGDispatchCentralSystem::AllDelivered(){
		if(GetAvailableVehicles(this->orders[0]).size() == this->observers.size()){
			return true;
		}
		return false;
	}

    /**
     * This method retrieves the available freezer only vehicles from the queue
	 * @param a Order
	 * @return Freezer only vehicles
     * @precondition  (The instance of the object must exist)
     * @postcondition (The list of available freezer only vehicles is returned)
     */
	vector<AMGVehicleObserver *> AMGDispatchCentralSystem::GetFreezerOnlyVehicles(AMGOrder *a) {
		vector<AMGVehicleObserver *> freezer_only;
		vector<AMGVehicleObserver *> available;
		available = this->GetAvailableVehicles(a);
		for(int i = 0; i < available.size(); i++){
			if(available[i]->GetVehicle()->HasFreezer()){
				freezer_only.push_back(available[i]);
			}
		}
		freezer_only = AMGVehicleObserver::Sort(freezer_only, a);
		return freezer_only;
	}

	/**
	 * This method retrieves the available vehicles from the queue
	 * @param a Order
	 * @return Available vehicles
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The list of available vehicles is returned)
	 */
	vector<AMGVehicleObserver *> AMGDispatchCentralSystem::GetAvailableVehicles(AMGOrder *a){
		vector<AMGVehicleObserver *> vehicles;
		for(int i = 0; i < this->observers.size(); i++){
			AMGVehicleObserver *temp = static_cast<AMGVehicleObserver *>(this->observers[i]);
			if(temp != nullptr){
				if(temp->GetVehicle()->GetState() != VEHICLE_STATE::IN_TRANSIT){
					vehicles.push_back(temp);
				}
			}
		}
		vehicles = AMGVehicleObserver::Sort(vehicles, a);
		return vehicles;
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGDispatchCentralSystem::AMGDispatchCentralSystem() {
 		this->retries = 0;       
	}

    /**
     * This is the common constructor.
	 * @param a Number of high traffic events
     * @postcondition (A new instance of the object has been created.)
     */
    AMGDispatchCentralSystem::AMGDispatchCentralSystem(int a) {
		this->traffic_events = a;
		this->retries = 0;
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDispatchCentralSystem::~AMGDispatchCentralSystem() {
        for(int i = 0; i < observers.size(); i++) {
            delete observers[i];
        }
        observers.clear();
	}
   
    /**
     * This method adds an observer to the objects observers list
     * @param observer Observer object to add
     * @precondition  (The instance of the central system must exist)
     * @postcondition (The observer has subscribed to the subject)
     */
    void AMGDispatchCentralSystem::RegisterObserver(AMGCommonObserver *observer) {
        observers.push_back(observer);
    }
    
    /**
     * This method removes an observer from the objects observers list
     * @param observer Observer object to remove
     * @precondition  (The instance of the central system must exist)
     * @postcondition (The observer has unsubscribed to the subject)
     */
    void AMGDispatchCentralSystem::DeregisterObserver(AMGCommonObserver *observer) {
        for(int i = 0; i < observers.size(); i++) {
            if(observer == observers[i]) {
                observers.erase(observers.begin() + i);
            }
        }
    }
    
    /**
     * This method displays:
     * The vehicle identification. Vehicles are identified by numbers 0-9
     ** Whether refrigerated or not.
     ** The order and contents of the delivery each driver is delivering.
     ** How far they have gone if they are in transit and how much further to go
     ** If driver has reached his destination, it’s new distance from each store.
     * If a ”waiting” order is assigned to a new driver, which vehicle it is assigned to and then the delivery has to be tracked as above.
     * @precondition  (The instance of the central system must exist)
     * @postcondition (The statuses have been displayed)
     */
    void AMGDispatchCentralSystem::DisplayAll() {
        for(int i = 0; i < observers.size(); i++) {
         	this->observers[i]->Display();
        }
    }


    /**
     * This method finds an appropriate vehicle if any
	 * @param a Order to scan for
	 * @return The vehicle or null if none found
     * @precondition  (The instance of the central system must exist)
     * @postcondition (The vehicle is returned if found)
     */
	AMGVehicleObserver *AMGDispatchCentralSystem::Calculate(AMGOrder *a){
        vector<AMGVehicleObserver *> available = this->GetAvailableVehicles(a);
        AMGVehicleObserver *current_vehicle = nullptr;

		if(available.size() == 0){
			return nullptr;
		}

        // Check if contains cold food items
        if(a->HasColdFoods()){
        	// Check if there's a high traffic event
			// or if the order distance will be greater than 2 miles
			// Assume that if a customer is more than a mile away from the store, any vehicle 
			// would make the total distance greater than 2 miles.
            if(traffic_events > 0 || a->GetCustomer()->GetDistance(a->GetShop()->GetIdentity()) > 1){ 
				if(traffic_events > 0){
            		traffic_events--;
				}
                // Find available freezer vehicles only
                if(this->GetFreezerOnlyVehicles(a).size() > 0){
                	// Find closest distance
                    current_vehicle = this->GetFreezerOnlyVehicles(a).at(0);
					return current_vehicle;
                }
                else{
                	return nullptr;  // Stop scan
                }
            }
			else{
				// Try freezer only first
				if(this->GetFreezerOnlyVehicles(a).size() > 0){
					return this->GetFreezerOnlyVehicles(a).at(0);
				}
				// Pick the vehicle with the lowest distance
				else {
					return available.at(0);
				}
			}
        }
        else{
        	// Find closest distance vehicle
			// Assume that vehicle with lowest distance will produce lowest total distance
            current_vehicle = available.at(0);
        }
		return current_vehicle;
	}
    
    /**
     * This method recalculates any waiting orders
     * @precondition  (The instance of the central system must exist)
     * @postcondition (The orders are up to date)
     */
    void AMGDispatchCentralSystem::Calculate() {
		vector<AMGVehicleObserver *> available = this->GetAvailableVehicles(this->orders[0]);
        AMGVehicleObserver *current_vehicle = nullptr;

		// If there's any vehicles available
		if(available.size() > 0){

			// For each waiting order
			int i = 0;
			while(i < this->orders.size()){
				available = this->GetAvailableVehicles(this->orders[i]);
				if(available.size() == 0){
					break;
				}
				if(this->orders[i]->GetState() != ORDER_STATE::FILLED){
					current_vehicle = this->Calculate(this->orders[i]);
					if(current_vehicle){
						// If customer has a birthday
        				if(this->orders[i]->GetCustomer()->HasBirthday()){
            				// Add free gift to ordera
            				this->orders[i]->AddItem(new AMGItem(new AMGProductGift("Chocolate"), 1));
                            this->orders[i]->AddItem(new AMGItem(new AMGProductFlowers("Flowers"), 1));
        				}	
						// Dispatch delivery
						this->Dispatch(new AMGDelivery(this->orders[i], current_vehicle->GetVehicle()->GetDistance(this->orders[i]->GetShop()->GetIdentity()) + 
							this->orders[i]->GetCustomer()->GetDistance(this->orders[i]->GetShop()->GetIdentity())), current_vehicle); 
						this->orders.erase(this->orders.begin() + i);

					}
					else {
						this->orders[i]->SetState(ORDER_STATE::WAITING);
					}
				}
				i++;
			}
		}
    }
    
    /**
     * This method dispatches a waiting order to a specific driver
     * @precondition  (The instance of the central system must exist)
     * @postcondition (The orders are up to date and displays which vehicle it is assigned to and then the delivery has to be tracked as above)
     */
    void AMGDispatchCentralSystem::Dispatch(AMGDelivery *a, AMGVehicleObserver *b) {
		a->GetOrder()->SetState(ORDER_STATE::FILLED);
 		b->SetDelivery(a);
    }
    
    /**
     * This method polls the status of each vehicle, caclulates the next delivery, and dispatches any waiting order.
     * @precondition  (The instance of the object must exist)
     * @postcondition (Statuses are displayed and any waiting order is dispatched if available)
     */
    void AMGDispatchCentralSystem::PollStatuses() {
		while(this->orders.size() > 0 || !AllDelivered()){
			for(int i = 0; i < this->orders.size(); i++){
				if(this->orders[i]->GetState() == ORDER_STATE::DELIVERED){
					delete this->orders[i];
					this->orders.erase(this->orders.begin() + i);
				}
			}

            // Calculate
			this->Calculate();
			
			this->NotifyObservers();
            
        	// Display statuses
            this->DisplayAll();

			cout << "SLEEPING.... (" << this->orders.size() << " orders left; " << 
				this->GetAvailableVehicles(this->orders[0]).size() << " available vehicles; " << this->traffic_events << " high traffic events)" << endl;
			cout << "Waiting Orders:" << endl;
			for(int i = 0; i < this->orders.size(); i++){
				if(this->orders[i]->GetState() != ORDER_STATE::FILLED){
					cout << this->orders[i]->ToString() << endl;
				}
			}

			// Prevent infinite loop
			if(this->GetAvailableVehicles(this->orders[0]).size() == this->observers.size() && this->orders.size() > 0){
				retries++;
				// Allow several retries
				if(retries == max_retries){
					throw invalid_argument("You should never have all vehicles available with any order...");
				}
			}

			cout << "Available Vehicles: " << endl;
			vector<AMGVehicleObserver *>available = this->GetAvailableVehicles(this->orders[0]);
			for(int i = 0; i < available.size(); i++){
				cout << available[i]->GetVehicle()->ToString() << endl;
			}

			AMGSystem::Sleep(tick_delay_seconds);
		}
    }
    
    /**
     * This method lets all the observers know that data has been modified
     * @precondition  (The instance of the central system must exist)
     * @postcondition (The observers have been updated)
     */
    void AMGDispatchCentralSystem::NotifyObservers() {
        for(int i = 0; i < this->observers.size(); i++) {
			this->observers[i]->Update(distance_per_tick);
        }
    }
    
    /**
     * This method sets the data of the object
     * @param Data
     * @precondition  (The instance of the object must exist)
     * @postcondition (The data of the object is set)
     */
    void AMGDispatchCentralSystem::SetOrders(vector<AMGOrder *> a) {
        this->orders = a;
        PollStatuses();
    }
}
