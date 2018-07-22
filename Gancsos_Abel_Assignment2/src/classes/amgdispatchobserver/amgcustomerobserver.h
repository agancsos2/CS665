#ifndef __AMGCUSTOMEROBSERVER_H_INCLUDED
#define __AMGCUSTOMEROBSERVER_H_INCLUDED

#include <iostream>
#include <string>
#include "amgcommonobserver.h"
#include "../amgcommon/amgcommon_all.h"
#include "../amgdispatchcommon/amgdispatchcommon_all.h"
using namespace std;
using namespace amgdispatchcommon;
using namespace amgcommon;

namespace amgdispatchobserver {

	class AMGCustomerObserver : public AMGCommonObserver {

		private:
			shared_ptr<AMGCustomer> customer;
        	const static int notify_delay_seconds = 2;
		public:
			AMGCustomerObserver();
			~AMGCustomerObserver();
			AMGCustomerObserver(shared_ptr<AMGCustomer> a);
			void Update(shared_ptr<AMGDelivery> delivery, int distance);
        	void Display();
	};	
}

#endif


