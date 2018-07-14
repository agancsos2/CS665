#ifndef __AMGDISPATCHDISPLAY_H_INCLUDED
#define __AMGDISPATCHDISPLAY_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

namespace amgdispatchobserver {

	class AMGDispatchDisplay {
		public:
			AMGDispatchDisplay();
			virtual ~AMGDispatchDisplay();
			virtual void Display() = 0;
	};
}

#endif
