#ifndef __AMGPRODUCTFOOD_H_INCLUDED__
#define __AMGPRODUCTFOOD_H_INCLUDED__

#include <iostream>
#include <vector>
#include <string>
#include "amgproduct.h"
using namespace std;

namespace amgdispatchcommon {

	enum class FOOD_TYPE {
		NONE,
		HOT,
		COLD
	};

    /**
     * This class represents a food product object
     */
    class AMGProductFood : public AMGProduct {
		protected:
			FOOD_TYPE food_type;
		public:
			AMGProductFood();
			~AMGProductFood();
			AMGProductFood(string name, FOOD_TYPE type);
			string GetType();
			string GetName();
			FOOD_TYPE GetFoodType();
			void SetName(string name);
			void SetFoodType(FOOD_TYPE type);
			string ToString();
    };
}
#endif

