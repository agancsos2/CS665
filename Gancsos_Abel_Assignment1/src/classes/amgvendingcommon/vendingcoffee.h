#ifndef __VENDINGCOFFEE_H_INCLUDED__
#define __VENDINGCOFFEE_H_INCLUDED__

#include <string>
#include <vector>
#include "vendingdrink.h"
#include "../amgcommon/amgcommon_all.h"
using namespace std;
using namespace amgcommon;

namespace amgvendingcommon{
    enum class COFFEE_SORTS {
        NONE = 0,
        ESPRESSO = 1,
        AMERICANO = 2,
        LATTE_MACCHIATO = 3  
    };

    /**
     * This class represents a coffee type drink
     */
    class VendingCoffee : public VendingDrink {
        private:
            COFFEE_SORTS sort;
			void AddCondiments();
        public:
            VendingCoffee();
            ~VendingCoffee(); 
            void SetSort(COFFEE_SORTS a);
            COFFEE_SORTS GetSort();  
            string GetType();
            string ToString();
            void AddCondiment(DrinkCondiment *a);
            void RemoveCondiment(DrinkCondiment *a);
            static COFFEE_SORTS EnsureSortByName(string a);
            vector<string> GetSorts();
            void Brew();
    };
}
#endif
