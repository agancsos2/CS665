#ifndef __AMGDELIVERY_H_INCLUDED__
#define __AMGDELIVERY_H_INCLUDED__

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "amgorder.h"
using namespace std;

namespace amgdispatchcommon {
    /**
     * This class represents a delivery object
     */
    class AMGDelivery {
    	private:
        	int delivery_id;
        	AMGOrder *order;
			int total_distance;
        public:
        	AMGDelivery();
        	~AMGDelivery();
			AMGDelivery(AMGOrder *order, int distance);
			AMGOrder *GetOrder();
			void SetOrder(AMGOrder *order);
        	string ToString();
			void SetTotalDistance(int distance);
			int GetTotalDistance();
    };
}
#endif
