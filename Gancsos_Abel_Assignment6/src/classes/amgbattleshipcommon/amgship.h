#ifndef __AMGSHIP_H_INCLUDED
#define __AMGSHIP_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "amglocation.h"
using namespace std;

namespace amgbattleshipcommon {
	class AMGShip {
		private:
			vector<shared_ptr<AMGLocation> > location;
		public:
			AMGShip();
			AMGShip(int a, int b);
			~AMGShip();
			vector<shared_ptr<AMGLocation> > GetLocation();
			string ToString();
			void AddLocation(shared_ptr<AMGLocation> a);
			void RemoveLocation(shared_ptr<AMGLocation> a);
	};
}

#endif
