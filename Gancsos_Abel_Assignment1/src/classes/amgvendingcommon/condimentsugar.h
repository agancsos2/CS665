#ifndef __CONDIMENTSUGAR_H_INCLUDED__
#define __CONDIMENTSUGAR_H_INCLUDED__

#include <string>
#include <vector>
#include "drinkcondiment.h"
using namespace std;

namespace amgvendingcommon{
    /**
     * This class represents a sugar condiment type
     */
    class CondimentSugar : public DrinkCondiment {
        public:
            CondimentSugar();
            CondimentSugar(int a);
            ~CondimentSugar();   
            string ToString();
            string GetType();
    };
}
#endif

