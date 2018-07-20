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
			vector<int> distances;
		public:
			AMGCustomer();
			~AMGCustomer();
			AMGCustomer(int distance);
            int GetDistance(int a);
            void AddDistance(int a);
            void RemoveDistance(int a);
            void SetDistance(int a, int b);
			string GetType();
			string ToString();
        	AMGCustomer(string first, string last, int age);
            vector<int> GetDistances();
    };
}
#endif

