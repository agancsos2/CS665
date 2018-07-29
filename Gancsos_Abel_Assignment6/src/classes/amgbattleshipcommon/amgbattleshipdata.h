#ifndef __AMGBATTLESHIPDATA_H_INCLUDED
#define __AMGBATTLESHIPDATA_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "amgship.h"
#include "amglocation.h"
using namespace std;

namespace amgbattleshipcommon {
    class AMGBattleshipData {
        private:
            int player_number;
            bool is_shot;
            vector<shared_ptr<AMGShip> > player_ships;
            int player_ships_left;
            vector<shared_ptr<AMGLocation> > player_shots;
            bool IsLocationHit(shared_ptr<AMGLocation> a);
        public:
            AMGBattleshipData();
            ~AMGBattleshipData();
            AMGBattleshipData(int a);
            void SetPlayerNumber(int a);
            bool NotAleradyShot(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGLocation> > b);
            int GetPlayerNumber();
            void Forfeit();
            void AddShip(shared_ptr<AMGLocation> a);
            int GetShipCount();
            void AddShot(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipData> b);
            bool WasShot();
            vector<shared_ptr<AMGLocation> > GetPlayerShots();
            vector<shared_ptr<AMGShip> > GetPlayerShips();
            int GetShipsLeft();
            bool IsLocationHit(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b);
            bool AlreadyShot(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGLocation> > b);
            bool ShipAtLocation(shared_ptr<AMGLocation> a);
            bool ShipAtLocation(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b);
            void SetShipCount(int a);
            void AddShot(shared_ptr<AMGLocation> a);
    };
}

#endif

