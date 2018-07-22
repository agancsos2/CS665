#include "amgdispatch.h"
namespace amgdispatch {

	/**
	 * This method prepares the system with the simulated data
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The simulated data has been created in memory)
	 * @todo Create these objects using an Abstract Factory.  
	 * There was no time in module 2 to redesign implementation
	 */
	void AMGDispatch::FillSimulatedData(){
		// Create customers
		vector<shared_ptr<AMGCustomer> > customers;
		for(int i = 0; i < order_count; i++){
			shared_ptr<AMGCustomer> temp(new AMGCustomer("Test" + to_string(i), "Customer", (rand() % 80 + 18)));
			for(int i = 0; i < shop_count; i++){
				temp->AddDistance((rand() % order_count) + 2);
			}
			temp->SetBirthday(((rand() % 1) == 1 ? true : false));
			customers.push_back(temp);
		}

		// Create vehicles
		for(int i = 0; i < driver_count; i++){
			shared_ptr<AMGVehicle> temp(new AMGVehicle("Vehicle" + to_string(i), ((rand() % 2 + 1) == 1 ? true : false)));
            for(int i = 0; i < shop_count; i++){
                temp->AddDistance((rand() % driver_count) + 2);
            }
			vehicles.push_back(temp);
		}

		// Create shops
		vector<shared_ptr<AMGShop> > shops;
		for(int i = 0; i < shop_count; i++){
			// Add products to shops
			vector<shared_ptr<AMGProduct> > store_products;
			for(int j = 0; j < product_count; j++){

				// Randomize the product type (food or flower)
				int temp_type = (rand() % 2 + 1);

				// Food
				if(temp_type == 1){
					// Randomize food type (hot or cold)
					int temp_type2 = (rand() % 3 == 0 ? 1 : 0);
					store_products.push_back(shared_ptr<AMGProduct>(new AMGProductFood("Store" + to_string(i) + "Item" + to_string(j), (temp_type2 == 1 ? FOOD_TYPE::HOT : FOOD_TYPE::COLD))));
				}
				// Flower
				else if(temp_type == 2){
					store_products.push_back(shared_ptr<AMGProduct>(new AMGProductFlowers("Store" + to_string(i) + "Item" + to_string(j))));
				}
			}
			shops.push_back(shared_ptr<AMGShop>(new AMGShop("Shop" + to_string(i), (rand() % shop_count + 1), store_products)));
			shops[i]->SetIdentity(i);
			
		}
		// Create orders
		for(int i = 0; i < order_count; i++){
			shared_ptr<AMGOrder> temp(new AMGOrder());
			int rand_customer_index = (rand() % customers.size());
			temp->SetCustomer(customers[rand_customer_index]);
			customers.erase(customers.begin() + rand_customer_index);    

            shared_ptr<AMGShop> temp_store = shops[(rand() % shops.size())];
			temp->SetShop(temp_store);
		    
			// Add items to orders
			for(int j = 0; j < (rand() % 3 + 1); j++){
				shared_ptr<AMGProduct> temp_product = temp_store->GetProducts()[(rand() % temp_store->GetProducts().size())];
				shared_ptr<AMGItem> temp_item(new AMGItem(temp_product, (rand() % 5 + 1)));
				temp->AddItem(temp_item);
			}

    	    // Add to orders collection
			orders.push_back(temp);
		}
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
    AMGDispatch::AMGDispatch(){
        this->batchable = false;
		this->env = new AMGDispatchCentralSystem(high_traffic_count);
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGDispatch::~AMGDispatch(){
		orders.clear();
		vehicles.clear();
        delete env;
    }

    /**
     * This method sets the mode to batchable
     * @param a Value to set for the flag
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is set)
     */
    void AMGDispatch::SetBatchable(bool a){
        batchable = a;
    }

    /**
     * This method retrieves the batchable flag
     * @return        (Value of the flag)
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is returned)
     */
    bool AMGDispatch::GetBatchable(){
        return batchable;
    }

    /**
     * This method is the main entry to the controller and prepares the session
     * @precondition  (The instance of the object exists)
     * @postcondition (The patron is prompted or the operations are ran in batch mode)
     */
    void AMGDispatch::AMGDispatch::Run(){
        FillSimulatedData();

        // Address issue where the first distance for each customer is set to zero
        for(int i = 0; i < orders.size(); i ++){
            orders[i]->GetCustomer()->SetDistance(0, rand() % order_count + 1);
        }

        // Register the vehicles as observers
		for(shared_ptr<AMGVehicle> cursor : vehicles){
			this->env->RegisterObserver(shared_ptr<AMGCommonObserver>(new AMGVehicleObserver(cursor)));			
		}
		env->SetOrders(orders);
    }
}
