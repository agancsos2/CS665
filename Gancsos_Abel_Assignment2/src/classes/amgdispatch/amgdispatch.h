#ifndef __AMGVENDING_H_INCLUDED__  
#define __AMGVENDING_H_INCLUDED__ 

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <memory>
#include <time.h>
#include "../amgcommon/amgcommon_all.h"
#include "amgdispatch_all.h"
#include "../amgdispatchcommon/amgdispatchcommon_all.h"
#include "../amgdispatchsubject/amgdispatchsubject_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgdispatchcommon;
using namespace amgdispatchsubject;

namespace amgdispatch{
	/**
 	 * This class acts as a "session" or wrapping class for the dispatch system.
     * This class serves as single location to configure the central system for the observations.
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
 	 */
	class AMGDispatch {
		private:
			bool batchable;
			void FillSimulatedData();
        	AMGDispatchCentralSystem *env;
			string input_buffer;
			vector<shared_ptr<AMGOrder> > orders;
			vector<shared_ptr<AMGVehicle> > vehicles;
			vector<shared_ptr<AMGProduct> > products;
			const static int driver_count = 10;
			const static int order_count = 20;
			const static int shop_count = 5;
			const static int product_count = 5;
			const static int high_traffic_count = 1;
		public:
			AMGDispatch();
			~AMGDispatch();
			void SetBatchable(bool a);
			bool GetBatchable();
			void Run();
	};
}

#endif
