#ifndef __AMGBATTLESHIPTARGET_H_INCLUDED
#define __AMGBATTLESHIPTARGET_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../amgbattleship/amgbattleshipboard.h"
#include "../amgbattleshipcommon/amglocation.h"
using namespace std;
using namespace amgbattleshipcommon;
using namespace amgbattleship;

namespace amgbattleshipcommand {


	/**
	 * This class represents the request object for the command
	 */
    class AMGBattleshipTarget{

		private:
        public:
        shared_ptr<AMGLocation> location;
        shared_ptr<AMGBattleshipBoard> board;

            AMGBattleshipTarget();
			AMGBattleshipTarget(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipBoard> b);
            ~AMGBattleshipTarget();
            void Shoot();
    };
}

#endif

