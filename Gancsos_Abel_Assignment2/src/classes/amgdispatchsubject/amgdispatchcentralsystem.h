#ifndef __AMGDISPATCHCENTRALSYSTEM_H_INCLUDED
#define __AMGDISPATCHCENTRALSYSTEM_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include "../amgcommon/amgcommon_all.h"
#include "../amgdispatchobserver/amgdispatchobserver_all.h"
#include "../amgdispatchsubject/amgdispatchsubject_all.h"
#include "../amgdispatchcommon/amgdispatchcommon_all.h"
using namespace std;
using namespace amgdispatchobserver;
using namespace amgdispatchsubject;
using namespace amgdispatchcommon;
using namespace amgcommon;

namespace amgdispatchsubject {

	/**
	 * This class helps assign orders to appropriate vehicles.
	 * By design, all assignment tasks must be performed in this facility.
	 */
	class AMGDispatchCentralSystem : public AMGDispatchSubject {
		private:
        	vector<AMGCommonObserver *> observers;
        	vector<AMGOrder *> orders;
			int traffic_events;
			const static int max_retries = 3;
			int retries;
        	const static int tick_delay_seconds = 5;
			const static int distance_per_tick = 1;
        	void PollStatuses();
        	void DisplayAll();
        	void Calculate();
        	void Dispatch(AMGDelivery *a, AMGVehicleObserver *b);
			vector<AMGVehicleObserver *> GetAvailableVehicles(AMGOrder *a);
			vector<AMGVehicleObserver *> GetFreezerOnlyVehicles(AMGOrder *a);
			AMGVehicleObserver *Calculate(AMGOrder *a);
			bool AllDelivered();
		public:
			AMGDispatchCentralSystem();
			AMGDispatchCentralSystem(int a);
            ~AMGDispatchCentralSystem();
        	void SetOrders(vector<AMGOrder *> a);
        	void RegisterObserver(AMGCommonObserver *observer);
        	void DeregisterObserver(AMGCommonObserver *observer);
        	void NotifyObservers();
    };
}

#endif
