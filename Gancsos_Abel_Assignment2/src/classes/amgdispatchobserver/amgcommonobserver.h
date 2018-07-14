#ifndef __AMGCOMMONOBSERVER_H_INCLUDED
#define __AMGCOMMONOBSERVER_H_INCLUDED

#include <iostream>
#include "amgdispatchobserver.h"
#include "amgdispatchdisplay.h"
#include "../amgdispatchcommon/amgdispatchcommon_all.h"
using namespace std;
using namespace amgdispatchcommon;

namespace amgdispatchobserver {
	class AMGCommonObserver : public AMGDispatchObserver, public AMGDispatchDisplay {
		protected:
            int distance;
			AMGDelivery *delivery;
		public:
			AMGCommonObserver();
			virtual AMGDelivery *GetDelivery();
			virtual ~AMGCommonObserver();
			virtual void Update(int distance) = 0;		
			virtual void Display() = 0;
	};
}

#endif
