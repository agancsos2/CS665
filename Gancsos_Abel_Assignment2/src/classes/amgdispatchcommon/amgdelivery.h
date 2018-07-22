#ifndef __AMGDELIVERY_H_INCLUDED__
#define __AMGDELIVERY_H_INCLUDED__

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <memory>
#include "amgorder.h"
using namespace std;

namespace amgdispatchcommon {
    /**
     * This class represents a delivery object
     */
    class AMGDelivery {
    	private:
        	int delivery_id;
        	shared_ptr<AMGOrder> order;
			int total_distance;
        public:
        	AMGDelivery();
        	~AMGDelivery();
			AMGDelivery(shared_ptr<AMGOrder> order, int distance);
			shared_ptr<AMGOrder> GetOrder();
			void SetOrder(shared_ptr<AMGOrder> order);
        	string ToString();
			void SetTotalDistance(int distance);
			int GetTotalDistance();
    };
}
#endif
