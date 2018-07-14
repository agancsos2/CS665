#ifndef __AMGVEHICLE_H_INCLUDED__
#define __AMGVEHICLE_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include "amgdelivery.h"
using namespace std;

namespace amgdispatchcommon {

	enum class VEHICLE_STATE {
		NONE,
		READY,
		IN_TRANSIT,
		IDLE
	};

    /**
     * This class represents a vehcle object
     */
    class AMGVehicle {
		protected:
			int distance;
			string name;
			bool freezer;
			VEHICLE_STATE state;
		public:
			AMGVehicle();
			~AMGVehicle();
			AMGVehicle(string name, bool freezer);
			string GetName();
			string ToString();
			bool HasFreezer();
			int GetDistance();
        	void SetDistance(int a);
			static string GetStateName(VEHICLE_STATE a);
			void SetState(VEHICLE_STATE a);
			VEHICLE_STATE GetState();
    };
}
#endif

