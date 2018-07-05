#ifndef __CONDIMENTMILK_H_INCLUDED__
#define __CONDIMENTMILK_H_INCLUDED__

#include <string>
#include <vector>
#include "drinkcondiment.h"
using namespace std;

/**
 * This class represents a condiment of milk type
 */
class CondimentMilk : public DrinkCondiment {
    public:
    	CondimentMilk();
		CondimentMilk(int a);
		~CondimentMilk();
        string ToString();
        string GetType();
};

#endif

