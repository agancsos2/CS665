#ifndef __DRINKCONDIMENT_H_INCLUDED__
#define __DRINKCONDIMENT_H_INCLUDED__

#include <string>
#include <vector>
using namespace std;

namespace amgvendingcommon{
    /**
     * This class represents a drink condiment of any type
     */
    class DrinkCondiment {
        protected:
            int quantity;
        public:
            DrinkCondiment();
            virtual ~DrinkCondiment();
            DrinkCondiment(int a);
            virtual string ToString() = 0;
            virtual string GetType() = 0;
            int GetQuantity();
            void SetQuantity(int a);
    };
}
#endif

