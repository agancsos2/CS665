#ifndef __AMGSUBJECT_H_INCLUDED
#define __AMGSUBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "../amgdispatchobserver/amgdispatchobserver_all.h"
using namespace std;
using namespace amgdispatchobserver;

namespace amgdispatchsubject {

	class AMGDispatchSubject {
		protected:
			vector<AMGCommonObserver *> observers;
		public:
			AMGDispatchSubject();
			virtual ~AMGDispatchSubject();
			virtual void RegisterObserver(AMGCommonObserver *observer) = 0;
			virtual void DeregisterObserver(AMGCommonObserver *observer) = 0;
			virtual void NotifyObservers() = 0;
	};
		
}

#endif
