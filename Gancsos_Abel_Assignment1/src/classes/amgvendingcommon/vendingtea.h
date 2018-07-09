#ifndef __VENDINGTEA_H_INCLUDED__
#define __VENDINGTEA_H_INCLUDED__

#include <string>
#include <vector>
#include "vendingdrink.h"
#include "../amgcommon/amgcommon_all.h"
using namespace std;
using namespace amgcommon;

namespace amgvendingcommon{
    enum class TEA_SORTS {
        NONE = 0,
        BLACK = 1,
        GREEN = 2,
        YELLOW = 3   
    };

    /**
     * This class represents a tea type of drink
     */
    class VendingTea : public VendingDrink {
        private:
            TEA_SORTS sort;
			void AddCondiments();
			const static int brew_time_seconds = 5;
        public:
            VendingTea();
            ~VendingTea(); 
            void SetSort(TEA_SORTS a);
            TEA_SORTS GetSort();     
            string GetType();
            string ToString();
            void AddCondiment(DrinkCondiment *a);
            void RemoveCondiment(DrinkCondiment *a);
            static TEA_SORTS EnsureSortByName(string a);
            vector<string> GetSorts();
            void Brew();
    };
}
#endif
