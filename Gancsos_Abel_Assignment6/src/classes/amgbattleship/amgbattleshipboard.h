#ifndef __AMGBATTLESHIPBOARD_H_INCLUDED__
#define __AMGBATTLESHIPBOARD_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <time.h>
#include <stdlib.h>
#include "../amgbattleshipcommon/amgbattleshipcommon_all.h"
#include "../amgcommon/amgcommon_all.h"
#include "../amgbattleshipcommand/amgbattleshipcommand_all.h"
using namespace std;
using namespace amgbattleshipcommon;
using namespace amgcommon;
using namespace amgbattleshipcommand;

namespace amgbattleship{
    /**
     * This class represents the game board
     */
    class AMGBattleshipBoard{
		private:
			const string IS_HIT_GRAPHIC = "X";
			const string IS_SHOT_GRAPHIC = "-";
			const string IS_WATER_GRAPHIC = "*";
			int board_height;
			int board_width;
			int ship_count;
            shared_ptr<AMGBattleshipData> data;
            void GenerateShips();
		public:
			AMGBattleshipBoard();
			AMGBattleshipBoard(int a, int b, int c, int d);
			~AMGBattleshipBoard();
			void SetBoardHeight(int a);
			void SetBoardWidth(int a);
			void SetShipCount(int a);
			int GetBoardHeight();
			int GetBoardWidth();
			int GetShipCount();
			void PrintBoard(shared_ptr<AMGBattleshipData> opponent_data);
			void PrintHeader(shared_ptr<AMGBattleshipData> opponent_data);
            shared_ptr<AMGBattleshipData> GetData();
            void SubmitAttack(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipBoard> b);
	};
}
#endif
