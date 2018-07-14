#ifndef __AMGDISPATCHOBSERVER_H_INCLUDED
#define __AMGDISPATCHOBSERVER_H_INCLUDED

#include <iostream>
#include "../amgdispatchcommon/amgdispatchcommon_all.h"
using namespace std;
using namespace amgdispatchcommon;

namespace amgdispatchobserver {
	class AMGDispatchObserver {
		protected:
			int distance;
			AMGDelivery *delivery;
		public:
			AMGDispatchObserver();
			virtual ~AMGDispatchObserver();
			virtual void Update(int distance) = 0;
			virtual void Display() = 0;
	};
}

#endif
