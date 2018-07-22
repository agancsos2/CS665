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
			shared_ptr<AMGVehicle> vehicle;
        	const static int notify_delay_seconds = 3;
		public:
			AMGVehicleObserver();
			~AMGVehicleObserver();
			AMGVehicleObserver(shared_ptr<AMGVehicle> a);
			void Update(int distance);
        	void Display();
			shared_ptr<AMGVehicle> GetVehicle();
			void SetDelivery(shared_ptr<AMGDelivery> a);
			shared_ptr<AMGDelivery> GetDelivery();
			int GetDistance();
        	static vector<shared_ptr<AMGVehicleObserver> > Sort(vector<shared_ptr<AMGVehicleObserver> > a, shared_ptr<AMGOrder> b);
	};	
}

#endif

