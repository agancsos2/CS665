#ifndef __AMGCUSTOMER_H_INCLUDED__
#define __AMGCUSTOMER_H_INCLUDED__

#include <iostream>
#include <vector>
#include "amgperson.h"
using namespace std;

namespace amgdispatchcommon {
    /**
     * This class represents a customer person object
     */
	class AMGCustomer : public AMGPerson {

		private:
			int distance;
		public:
			AMGCustomer();
			~AMGCustomer();
			AMGCustomer(int distance);
			int GetDistance();
			void SetDistance(int a);
			string GetType();
			string ToString();
        	AMGCustomer(string first, string last, int age);
    };
}
#endif

