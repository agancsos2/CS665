#ifndef __AMGVENDING_H_INCLUDED__  
#define __AMGVENDING_H_INCLUDED__ 

#include <iostream>
#include <vector>
#include "../amgcommon/amgcommon_all.h"
#include "amgvending_all.h"
#include "../amgvendingcommon/amgvendingcommon_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgvendingcommon;

namespace amgvending{
	/**
 	 * This class acts as a "session" or wrapping class for a vending transaction.
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
 	 */
	class AMGVending {
		private:
			bool batchable;
			int condiment_limit;
			string input_buffer;
			VendingDrink *drink;
			vector<string> drink_types;
			vector<string> drink_condiments;
			void RunInteractive();
			void RunBatchMode();
			void PrintMenu();
			void PromptDrinkType();
			void PromptDrinkSort();
			void PromptCondiments();
			void RunOperation();
			void Dispense();
		public:
			AMGVending();
			~AMGVending();
			void SetBatchable(bool a);
			bool GetBatchable();
			void Run();

			void SetDrinkType(string a);
			void SetDrinkSort(string a);
			void AddCondiments(vector<DrinkCondiment *> a);
	};
}

#endif
