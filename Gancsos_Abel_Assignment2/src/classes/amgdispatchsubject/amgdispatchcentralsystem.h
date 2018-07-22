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
        	vector<shared_ptr<AMGCommonObserver> > observers;
        	vector<shared_ptr<AMGOrder> > orders;
			int traffic_events;
			const static int max_retries = 3;
			int retries;
        	const static int tick_delay_seconds = 5;
			const static int distance_per_tick = 1;
        	void PollStatuses();
        	void DisplayAll();
        	void Calculate();
        	void Dispatch(shared_ptr<AMGDelivery> a, shared_ptr<AMGVehicleObserver> b);
			vector<shared_ptr<AMGVehicleObserver> > GetAvailableVehicles(shared_ptr<AMGOrder> a);
			vector<shared_ptr<AMGVehicleObserver> > GetFreezerOnlyVehicles(shared_ptr<AMGOrder> a);
			shared_ptr<AMGVehicleObserver> Calculate(shared_ptr<AMGOrder> a);
			bool AllDelivered();
		public:
			AMGDispatchCentralSystem();
			AMGDispatchCentralSystem(int a);
            ~AMGDispatchCentralSystem();
        	void SetOrders(vector<shared_ptr<AMGOrder> > a);
        	void RegisterObserver(shared_ptr<AMGCommonObserver> observer);
        	void DeregisterObserver(shared_ptr<AMGCommonObserver> observer);
        	void NotifyObservers();
    };
}

#endif
