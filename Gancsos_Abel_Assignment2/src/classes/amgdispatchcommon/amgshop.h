#ifndef __AMGSHOP_H_INCLUDED__
#define __AMGSHOP_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "amgproduct.h"
using namespace std;

namespace amgdispatchcommon {
    /**
     * This class represents a shop object
     */
    class AMGShop {
        protected:
            int identity;
            int distance;
            string name;
			vector<AMGProduct *> products;
        public:
            AMGShop();
            ~AMGShop();
            AMGShop(string name, int distance, vector<AMGProduct *> products);
            string GetName();
            void SetIdentity(int a);
            int GetIdentity();
            string ToString();
            vector<AMGProduct *> GetProducts();
            int GetDistance();
    };
}
#endif

