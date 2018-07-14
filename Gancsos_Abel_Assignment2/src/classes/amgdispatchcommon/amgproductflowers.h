#ifndef __AMGPRODUCTFLOWERS_H_INCLUDED__
#define __AMGPRODUCTFLOWERS_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include "amgproduct.h"
using namespace std;

namespace amgdispatchcommon {
    /**
     * This class represents a flower product object
     */
    class AMGProductFlowers : public AMGProduct {
		public:
			AMGProductFlowers();
			~AMGProductFlowers();
        	AMGProductFlowers(string name);
			string GetName();
			string GetType();
			string ToString();
    };
}
#endif

