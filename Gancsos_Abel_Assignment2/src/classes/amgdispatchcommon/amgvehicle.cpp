#include "amgvehicle.h"

namespace amgdispatchcommon {

    /**
     * This method retrieves the state of the object
     * @return State
     * @precondition  (The instance of the object must exist)
     * @postcondition (The state of the object is set)
     */
    VEHICLE_STATE AMGVehicle::GetState() {
        return this->state;
    }

    /**
     * This method sets the state of the object
     * @param a State
     * @precondition  (The instance of the object must exist)
     * @postcondition (The state of the object is set)
     */
    void AMGVehicle::SetState(VEHICLE_STATE a) {
        this->state = a;
    }
    
    /**
     * This method sets the distance of the object
     * @param a Distance
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distance of the object is set)
     */
    void AMGVehicle::SetDistance(int a) {
        this->distance = a;
    }


	/**
     * This method retrieves the name for the state
     * @param a State
     * @return Name of the state
     * @precondition  (The instance of the object must exist)
     * @postcondition (The name of the state is returned)
     */
    string AMGVehicle::GetStateName(VEHICLE_STATE a){
        switch(a){
            case VEHICLE_STATE::NONE:
                return "None";
            case VEHICLE_STATE::READY:
                return "Ready";
            case VEHICLE_STATE::IN_TRANSIT:
                return "In Transit";
            case VEHICLE_STATE::IDLE:
                return "Idle";
            default:
                return "None";
        }
    }

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGVehicle::AMGVehicle() {
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGVehicle::~AMGVehicle() {
	}

    /**
     * This is the common constructor.
     * @param name Name of the vehicle
	 * @param freezer Freezer of the vehicle
     * @postcondition (A new instance of the object has been created.)
     */
    AMGVehicle::AMGVehicle(string name, bool freezer) {
		this->name = name;
		this->freezer = freezer;
	}

    /**
     * This method returns the name of the object
     * @return        The name of the object 
     * @precondition  (The instance exists)
     * @postcondition (The name of the object is returned)
     */
    string AMGVehicle::GetName() {
		return name;
	}

	/**
     * This method returns the freezer property
     * @return        Freezer property
     * @precondition  (The instance exists)
     * @postcondition (The freezer property is returned)
     */
	bool AMGVehicle::HasFreezer(){
		return freezer;
	}

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
    string AMGVehicle::ToString() {
		string vehicle_string = "(";
		vehicle_string += ("Name: " + name);
		vehicle_string += ("; Distance: " + to_string(distance));
        vehicle_string += (this->freezer ? "; Freezer" : "; No Freezer");
		vehicle_string += ")";
		return vehicle_string;
	}

    /**
     * This method retrieves the distance of the object
     * @return Distance of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The distance of the object is returned)
     */
    int AMGVehicle::GetDistance() {
		return distance;
	}
}
