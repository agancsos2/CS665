#ifndef __AMGPRODUCTGIFT_H_INCLUDED__
#define __AMGPRODUCTGIFT_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include "amgproduct.h"
using namespace std;

namespace amgdispatchcommon {
    /**
     * This class represents a gift product object
     */
    class AMGProductGift : public AMGProduct {
		public:
			AMGProductGift();
			~AMGProductGift();
			AMGProductGift(string name);
			string GetName();
			string GetType();
			string ToString();
    };
}
#endif

