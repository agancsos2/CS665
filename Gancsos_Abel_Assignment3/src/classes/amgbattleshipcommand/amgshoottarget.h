#ifndef __AMGSHOOTCOMMAND_H_INCLUDED
#define __AMGSHOOTCOMMAND_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgbattleshipcommand.h"
#include "amgbattleshiptarget.h"

namespace amgbattleshipcommand {

	class AMGShootTarget : public AMGBattleshipCommand {

		private:
            shared_ptr<AMGBattleshipTarget> target;
		public:
			AMGShootTarget();
			AMGShootTarget(shared_ptr<AMGBattleshipTarget> a);
			~AMGShootTarget();
			void Execute();
	};
}

#endif
