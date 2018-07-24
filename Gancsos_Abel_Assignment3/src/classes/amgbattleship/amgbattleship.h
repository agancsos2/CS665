#ifndef __AMGBATTLESHIP_H_INCLUDED
#define __AMGBATTLESHIP_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../amgcommon/amgcommon_all.h"
#include "amgbattleshipboard.h"
#include "../amgbattleshipcommand/amgbattleshipcommand_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgbattleshipcommand;

namespace amgbattleship {

    /**
     * This class acts as a "session" or wrapping class for the game.
     * This class serves as single location to configure the game board.
     * @author  (Abel Gancsos)
     * @version (v. 1.0.0)
     */
	class AMGBattleship {
		private:
			shared_ptr<AMGBattleshipBoard> board;
			string input_buffer;
			void PromptUser();
			int current_player;
			void PrintGameOver();
			void GenerateShips();
			const static int sleep_seconds = 8;
		public:
			AMGBattleship();
			~AMGBattleship();
			void SetBoardHeight(int a);
			void SetBoardWidth(int a);
			void SetShipCount(int a);
			void Run();
	};
}

#endif

