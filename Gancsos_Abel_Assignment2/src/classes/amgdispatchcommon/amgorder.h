#ifndef __AMGORDER_H_INCLUDED__
#define __AMGORDER_H_INCLUDED__

#include <iostream>
#include <vector>
#include "amgitem.h"
#include "amgcustomer.h"
#include "amgshop.h"
using namespace std;

namespace amgdispatchcommon {

	enum class ORDER_STATE {
		NONE,
		NEW,
		WAITING,
		FILLED,
		DELIVERED
	};
	
    /**
     * This class represents an order object
     */
	class AMGOrder {
		private:
			vector<AMGItem *> items;
        	AMGCustomer *customer;
        	AMGShop *shop;
			ORDER_STATE state;
		public:
			AMGOrder();
			~AMGOrder();
			ORDER_STATE GetState();
			void SetState(ORDER_STATE a);
			void AddItem(AMGItem *item);
			void RemoveItem(AMGItem *item);
			vector<AMGItem *> GetItems();
			string ToString();
        	void SetCustomer(AMGCustomer *a);
        	AMGCustomer *GetCustomer();
        	void SetShop(AMGShop *a);
        	AMGShop *GetShop();
			bool HasColdFoods();
			static string GetStateName(ORDER_STATE a);
    };
}
#endif

