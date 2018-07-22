#ifndef __AMGORDER_H_INCLUDED__
#define __AMGORDER_H_INCLUDED__

#include <iostream>
#include <vector>
#include "amgitem.h"
#include "amgcustomer.h"
#include <memory>
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
			vector<shared_ptr<AMGItem> > items;
        	shared_ptr<AMGCustomer> customer;
        	shared_ptr<AMGShop> shop;
			ORDER_STATE state;
		public:
			AMGOrder();
			~AMGOrder();
			ORDER_STATE GetState();
			void SetState(ORDER_STATE a);
			void AddItem(shared_ptr<AMGItem> item);
			void RemoveItem(shared_ptr<AMGItem> item);
			vector<shared_ptr<AMGItem> > GetItems();
			string ToString();
        	void SetCustomer(shared_ptr<AMGCustomer> a);
        	shared_ptr<AMGCustomer> GetCustomer();
        	void SetShop(shared_ptr<AMGShop> a);
        	shared_ptr<AMGShop> GetShop();
			bool HasColdFoods();
			static string GetStateName(ORDER_STATE a);
    };
}
#endif

