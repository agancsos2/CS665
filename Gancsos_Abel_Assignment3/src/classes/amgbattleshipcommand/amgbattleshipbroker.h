#ifndef __AMGBATTLESHIPBROKER_H_INCLUDED
#define __AMGBATTLESHIPBROKER_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbattleshipcommand.h"
using namespace std;

namespace amgbattleshipcommand {


    /**
     * This class represents the invoker object for the command
     */
  	class AMGBattleshipBroker{

        private:
			vector<shared_ptr<AMGBattleshipCommand> > attacks;
        public:
            AMGBattleshipBroker();
            ~AMGBattleshipBroker();
            void ExecuteAttacks();
            void AddTarget(shared_ptr<AMGBattleshipCommand> a);
    };
}

#endif
