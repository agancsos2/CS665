#ifndef __AMGBATTLESHIPTARGET_H_INCLUDED
#define __AMGBATTLESHIPTARGET_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../amgbattleshipcommon/amgbattleshipcommon_all.h"
using namespace std;
using namespace amgbattleshipcommon;
//using namespace amgbattleship;

namespace amgbattleshipcommand {


	/**
	 * This class represents the request object for the command
	 */
    class AMGBattleshipTarget{

		private:
            shared_ptr<AMGLocation> location;
            shared_ptr<AMGBattleshipData> player_data;
            shared_ptr<AMGBattleshipData> opponent_data;
        public:
            AMGBattleshipTarget();
            AMGBattleshipTarget(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipData> b, shared_ptr<AMGBattleshipData> c);
            ~AMGBattleshipTarget();
            void Execute();
    };
}

#endif

