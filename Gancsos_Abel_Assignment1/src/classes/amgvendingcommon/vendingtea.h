#ifndef __VENDINGTEA_H_INCLUDED__
#define __VENDINGTEA_H_INCLUDED__

#include <string>
#include <vector>
#include "vendingdrink.h"
using namespace std;

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

#endif
