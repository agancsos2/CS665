#ifndef __AMGDRIVER_H_INCLUDED__
#define __AMGDRIVER_H_INCLUDED__

#include <iostream>
#include <vector>
#include "amgperson.h"
using namespace std;

namespace amgdispatchcommon {
    /**
     * This class represents a driver person object
     */
	class AMGDriver : public AMGPerson {

		public:
			AMGDriver();
			~AMGDriver();
			string GetType();
			string ToString();
    };
}
#endif

