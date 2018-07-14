#ifndef __AMGITEM_H_INCLUDED__
#define __AMGITEM_H_INCLUDED__

#include <iostream>
#include <vector>
#include "amgproduct.h"
#include "amgproductfood.h"
using namespace std;

namespace amgdispatchcommon {

    class AMGItem {
        private:
			AMGProduct *product;
			int quantity;
        public:
            AMGItem();
            ~AMGItem();
			AMGItem(AMGProduct *product, int q);
			void SetProduct(AMGProduct *product);
			AMGProduct *GetProduct();
			void SetQuantity(int q);
			int GetQuantity();
			string ToString();
			string GetType();
			bool Equals(AMGItem *item2);
    };
}
#endif

