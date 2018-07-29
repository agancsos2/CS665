#ifndef __AMGBATTLESHIPCOMMAND_H_INCLUDED
#define __AMGBATTLESHIPCOMMAND_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbattleshiptarget.h"
using namespace std;

namespace amgbattleshipcommand {

	class AMGBattleshipCommand {
        protected:
            shared_ptr<AMGBattleshipTarget> target;
		public:
			AMGBattleshipCommand();
			virtual ~AMGBattleshipCommand();
			virtual void Execute() = 0;
	};
}

#endif
