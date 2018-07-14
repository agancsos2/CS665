#ifndef __AMGVEHICLEOBSERVER_H_INCLUDED
#define __AMGVEHICLEOBSERVER_H_INCLUDED

#include <iostream>
#include <string>
#include "amgcommonobserver.h"
#include "../amgcommon/amgcommon_all.h"
#include "../amgdispatchcommon/amgdispatchcommon_all.h"
using namespace std;
using namespace amgdispatchcommon;
using namespace amgcommon;

namespace amgdispatchobserver {

	class AMGVehicleObserver : public AMGCommonObserver {

		private:
			AMGVehicle *vehicle;
        	const static int notify_delay_seconds = 3;
		public:
			AMGVehicleObserver();
			~AMGVehicleObserver();
			AMGVehicleObserver(AMGVehicle *a);
			void Update(int distance);
        	void Display();
			AMGVehicle *GetVehicle();
			void SetDelivery(AMGDelivery *a);
			AMGDelivery *GetDelivery();
	};	
}

#endif

