#include "amgitem.h"

namespace amgdispatchcommon {

	/**
	 * This method checks if the current item is equal to another
	 * @return True if yes, false if no
	 * @param item2 Item to compare to
	 * @precondition  (Both instances of the object must exist)
	 * @postcondition (The result of the comparison)
	 */
	bool AMGItem::Equals(shared_ptr<AMGItem> item2){
		if(this->product->ToString() == item2->ToString()){
			return true;
		}
		return false;		
	}

    /**
     * This method retrieves the type of the object
     * @return Type of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The type of the object is returned)
     */
	string AMGItem::GetType(){
		return product->GetType();
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGItem::AMGItem() {
		this->product = shared_ptr<AMGProduct>(new AMGProductFood());
		this->quantity = 0;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGItem::~AMGItem() {
	}

    /**
     * This is the common constructor.
     * @param product Product of the object
     * @param q Quantity of the item
     * @postcondition (A new instance of the object has been created.)
     */
    AMGItem::AMGItem(shared_ptr<AMGProduct> product, int q) {
		this->product = product;
		this->quantity = q;
	}

    /**
     * This method sets the product of the object
     * @param product Product of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The product of the object is set)
     */
    void AMGItem::SetProduct(shared_ptr<AMGProduct> product) {
		this->product = product;
	}

    /**
     * This method retrieves the product of the object
     * @return Product of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The product of the object is returned)
     */
    shared_ptr<AMGProduct> AMGItem::GetProduct() {
		return this->product;
	}

    /**
     * This method sets the quantity of the object
     * @param q Quantity of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The quantity of the object is set)
     */
    void AMGItem::SetQuantity(int q) {
		this->quantity = q;
	}

    /**
     * This method retrieves the quantity of the object
     * @return Quantity of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The quantity of the object is returned)
     */
    int AMGItem::GetQuantity() {
		return quantity;
	}

    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
	string AMGItem::ToString() {
		string item_string = "(";
		item_string += ("Item: " + product->ToString());
		item_string += ("; Quantity: " + to_string(quantity));
		item_string += ")";
		return item_string;
	}
}
