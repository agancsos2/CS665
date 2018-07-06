#ifndef __VENDINGDRINK_H_INCLUDED__
#define __VENDINGDRINK_H_INCLUDED__

#include <string>
#include <vector>
#include "../amgcommon/amgcommon_all.h"
#include "drinkcondiment.h"
#include "condimentsugar.h"
#include "condimentmilk.h"
using namespace std;

namespace amgvendingcommon{
    /**
     * This class represents a drink of any type
     */
    class VendingDrink {
        protected:
            vector<DrinkCondiment*> condiments;
        public:
            VendingDrink();
            virtual ~VendingDrink();
            virtual string GetType() = 0;
            virtual string ToString() = 0;
            virtual void AddCondiment(DrinkCondiment *a) = 0;
            virtual void RemoveCondiment(DrinkCondiment *a) = 0; 
            virtual vector<string> GetSorts() = 0;
            virtual void Brew() = 0;
			virtual void AddCondiments() = 0;
    };
}
#endif
