#ifndef __AMGBATTLESHIPBOARD_H_INCLUDED__
#define __AMGBATTLESHIPBOARD_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdlib.h>
#include "../amgbattleshipcommon/amgbattleshipcommon_all.h"
#include "../amgcommon/amgcommon_all.h"
using namespace std;
using namespace amgbattleshipcommon;
using namespace amgcommon;

namespace amgbattleship{
    /**
     * This class represents the game board
     */
    class AMGBattleshipBoard{
		private:
            // @todo Create a client or data class and include these fields
			const string IS_HIT_GRAPHIC = "X";
			const string IS_SHOT_GRAPHIC = "-";
			const string IS_WATER_GRAPHIC = "*";
			int board_height;
			int board_width;
			int ship_count;
			bool is_shot;
			int current_player;
			vector<shared_ptr<AMGShip> > player1_ships;
			vector<shared_ptr<AMGShip> > player2_ships;
			int player1_ships_left;
			int player2_ships_left;
			vector<shared_ptr<AMGLocation> > player1_shots;
			vector<shared_ptr<AMGLocation> > player2_shots;
			bool IsLocationHit(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b);
            bool AlreadyShot(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGLocation> > b);
			bool ShipAtLocation(shared_ptr<AMGLocation> a);
			bool ShipAtLocation(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b);
		public:
			AMGBattleshipBoard();
			AMGBattleshipBoard(int a, int b, int c);
			~AMGBattleshipBoard();
			void SetBoardHeight(int a);
			void SetBoardWidth(int a);
			void SetShipCount(int a);
			int GetBoardHeight();
			int GetBoardWidth();
			int GetShipCount();
			void PrintBoard();
			int GetPlayer1ShipCount();
			int GetPlayer2ShipCount();
			void SetCurrentPlayer(int a);
            void Forfeit();
            void AddShip(shared_ptr<AMGLocation> a, int b);
			int GetShipCount(int a);
            bool IsLocationHit(shared_ptr<AMGLocation> a);
			void AddShot(shared_ptr<AMGLocation> a);
			void PrintHeader();
			bool WasShot();
	};
}
#endif
