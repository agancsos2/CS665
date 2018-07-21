#include "amgorder.h"

namespace amgdispatchcommon {

    /**
     * This method retrieves the state of the object
     * @return State
     * @precondition  (The instance of the object must exist)
     * @postcondition (The state of the object is set)
     */
	ORDER_STATE AMGOrder::GetState() {
		return this->state;
	}

    /**
     * This method sets the state of the object
     * @param a State
     * @precondition  (The instance of the object must exist)
     * @postcondition (The state of the object is set)
     */
    void AMGOrder::SetState(ORDER_STATE a) {
		this->state = a;
	}

    /**
	 * This method checks if the order has any cold foods
	 * @return True if it does, false if not
	 * @precondition  (Instance of the object must exist)
	 * @postcondition (The results of the search is returned)
	 */
	bool AMGOrder::HasColdFoods(){
		for(int i = 0; i < this->items.size(); i++){
			if(this->items[i]->GetProduct()->GetType() == "Food"){
				if(dynamic_cast<AMGProductFood *>(this->items[i]->GetProduct())->GetFoodType() == FOOD_TYPE::COLD){
					return true;
				}
			}
		}
		return false;
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGOrder::AMGOrder() {
        this->customer = nullptr;
        this->shop = nullptr;
		this->state = ORDER_STATE::NEW;
		
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGOrder::~AMGOrder() {
        for(int i = 0; i < items.size(); i++){
            delete items[i];
        }
        //delete customer;
	}
    
    /**
     * This method sets the shop of the object
     * @param a Shop
     * @precondition  (The instance of the object must exist)
     * @postcondition (The shop of the object is set)
     */
    void AMGOrder::SetShop(AMGShop *a) {
        this->shop = a;
    }
    
    /**
     * This method retrieves the shop of the object
     * @return Shop of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The shop of the object is returned)
     */
    AMGShop *AMGOrder::GetShop() {
        return this->shop;
    }
    
    /**
     * This method sets the customer of the object
     * @param a Customer
     * @precondition  (The instance of the object must exist)
     * @postcondition (The customer of the object is set)
     */
    void AMGOrder::SetCustomer(AMGCustomer *a){
        this->customer = a;
    }
    
    /**
     * This method retrieves the customer of the object
     * @return Customer of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The customer of the object is returned)
     */
    AMGCustomer *AMGOrder::GetCustomer() {
        return this->customer;
    }

    /**
     * This method add an item to the object's items
     * @param item Item object to add
     * @precondition  (The instance of the object must exist)
     * @postcondition (The new item is added if it does not exist)
     */
    void AMGOrder::AddItem(AMGItem *item) {
        if(this->items.size() == 0){
            this->items.push_back(item);
        }
        else{
            for(int i = 0; i < this->items.size(); i++){
                if(this->items[i]->GetType() != item->GetType()){
                    this->items.push_back(item);
                }
            }
        }
	}

    /**
     * This method removes the item from the object's items
     * @param item Item to remove
     * @precondition  (The instance of the object must exist)
     * @postcondition (The item is removed if it exists)
     */
    void AMGOrder::RemoveItem(AMGItem *item) {
		for(int i = 0; i < items.size(); i++) {
			if(items[i]->Equals(item)){
				items.erase(items.begin() + i);
			}
		}
	}

    /**
     * This method retrieves the name for the state
	 * @param a State
     * @return Name of the state
     * @precondition  (The instance of the object must exist)
     * @postcondition (The name of the state is returned)
     */
	string AMGOrder::GetStateName(ORDER_STATE a){
		switch(a){
			case ORDER_STATE::NONE:
				return "None";
			case ORDER_STATE::NEW:
				return "New";
			case ORDER_STATE::WAITING:
				return "Waiting";
			case ORDER_STATE::FILLED:
				return "Filled";
			case ORDER_STATE::DELIVERED:
				return "Delivered";
			default:
				return "None";
		}
	}

    /**
     * This method retrieves the items of the object
     * @return Items of the object
     * @precondition  (The instance of the object must exist)
     * @postcondition (The items of the object is returned)
     */
    vector<AMGItem *> AMGOrder::GetItems() {
		return this->items;
	}
    
    /**
     * This method returns the object as a string representation
     * @return        (A string representation of the object)
     * @precondition  (The instance exists)
     * @postcondition (The string representation of the class is returned)
     */
	string AMGOrder::ToString(){
		string order_string = "(";
		order_string += ("Customer: " + customer->ToString());
		order_string += (";State: " + GetStateName(this->state));
		order_string += (";Items: ");
		for(int i = 0; i < this->items.size(); i++){
			order_string += this->items[i]->ToString();
		} 
		order_string += ")";
		return order_string;
	}
}
