#ifndef __AMGLOCATION_H_INCLUDED
#define __AMGLOCATION_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

namespace amgbattleshipcommon {
    class AMGLocation {
        private:
            int x_coordinates;
            int y_coordinates;
        public:
            AMGLocation();
            AMGLocation(int a, int b);
            ~AMGLocation();
            void SetXCoordinates(int a);
            void SetYCoordinates(int a);
            int GetXCoordinates();
            int GetYCoordinates();
            string ToString();
			bool Equals(shared_ptr<AMGLocation> a);
    };
}

#endif

