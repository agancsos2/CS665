#ifndef __AMGITEM_H_INCLUDED__
#define __AMGITEM_H_INCLUDED__

#include <iostream>
#include <vector>
#include "amgproduct.h"
#include <memory>
#include "amgproductfood.h"
using namespace std;

namespace amgdispatchcommon {

    class AMGItem {
        private:
			shared_ptr<AMGProduct> product;
			int quantity;
        public:
            AMGItem();
            ~AMGItem();
			AMGItem(shared_ptr<AMGProduct> product, int q);
			void SetProduct(shared_ptr<AMGProduct> product);
			shared_ptr<AMGProduct> GetProduct();
			void SetQuantity(int q);
			int GetQuantity();
			string ToString();
			string GetType();
			bool Equals(shared_ptr<AMGItem> item2);
    };
}
#endif

