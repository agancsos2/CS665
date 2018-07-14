#ifndef __AMGPRODUCT_H_INCLUDED__
#define __AMGPRODUCT_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace amgdispatchcommon {
    
    /**
     * This class represents a product object
     */
	class AMGProduct {
		protected:
			string name;
		public:
			AMGProduct();
			virtual ~AMGProduct();
			virtual string GetName() = 0;
			virtual string GetType() = 0;
			virtual string ToString() = 0;
    };
}
#endif

