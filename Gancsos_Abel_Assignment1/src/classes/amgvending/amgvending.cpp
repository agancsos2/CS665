#include "amgvending.h"
namespace amgvending {
    /**
     * This method sets the drink type by name value
     * @precondition  (The session instance must exist and a valid value provided)
     * @postcondition (Drink type is updated if valid, otherwise a message is displayed)
     */
    void AMGVending::SetDrinkType(string a){
        if(AMGString(a).ToLowerCase() == "coffee"){
            drink = new VendingCoffee();
        }
        else if(AMGString(a).ToLowerCase() == "tea"){
            drink = new VendingTea();
        }
        else{
            cout << "Invalid drink type: " << a << endl;
            drink = nullptr;
        }
    }

    /**
     * This method sets the sort type by name value
     * @precondition  (The session instance must exist and a valid value provided)
     * @postcondition (Drink sort is updated if valid, otherwise a message is displayed)
     */
    void AMGVending::SetDrinkSort(string a){
        if(drink != nullptr){
            if(drink->GetType() == "Coffee"){
                dynamic_cast<VendingCoffee *>(drink)->SetSort(VendingCoffee::EnsureSortByName(a));
            }
            else if(drink->GetType() == "Tea"){
                dynamic_cast<VendingTea *>(drink)->SetSort(VendingTea::EnsureSortByName(a));
            }
        }
        else{
            cout << "Drink is not of valid type..." << endl;
        }	
    }

    /**
     * This method adds the condiments to the drink
     * @precondition  (The session instance must exist and valid values provided)
     * @postcondition (Drink condiments are added if valid, otherwise a message is displayed)
     */
    void AMGVending::AddCondiments(vector<DrinkCondiment *> a){
        if(drink != nullptr){
            for(int i = 0; i < a.size(); i++){
                if(a[i]->GetQuantity() <= condiment_limit && a[i]->GetQuantity() > 0){
                    drink->AddCondiment(a[i]);
                }
                else{
                    cout << "(Condiment Quantity) Value is out of scope: " << a[i]->GetQuantity() << endl;
                }
            }
        }
        else{
            cout << "Drink is not of valid type..." << endl;
        }
    }


    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
    AMGVending::AMGVending(){
        batchable = false;
        condiment_limit = 3;
        input_buffer = "";
        drink = new VendingCoffee();
        drink_types.push_back("Coffee");
        drink_types.push_back("Tea");
        drink_condiments.push_back("Milk");
        drink_condiments.push_back("Sugar");
    }

    /**
     * This method performs session operations with user input
     * @precondition  (The instance of the object exists)
     * @postcondition (The patron is prompted)
     */
    void AMGVending::RunInteractive(){
        while(0 == 0){
            PrintMenu();
            RunOperation();
        }	
    }

    /**
     * This method runs the session in a batch mode
     * @precondition  (The instance of the object exists)
     * @postcondition (The operations are performed without user input)
     */
    void AMGVending::RunBatchMode(){
        RunOperation();
    }

    /**
     * This method prompts the user for drink type selection in an interactive session
     * @precondition  (The instance of the object exists)
     * @postcondition (The drink type is selected)
     */
    void AMGVending::PromptDrinkType(){
        while(!AMGSystem::IsDigit(input_buffer) || input_buffer == ""){
            cout << "Item options:" << endl;
            for(int i = 0; i < drink_types.size(); i++){
                cout << "\t* " << (i + 1) << ": " << drink_types[i] << endl;
            }
            cout << "Option: ";
            cin >> input_buffer;
            if(input_buffer == "#"){
                AMGSystem::ExitProgram();
            }
            if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
                if(stoi(input_buffer) - 1 < drink_types.size()){
                    SetDrinkType(drink_types[stoi(input_buffer) - 1]);
                }
                else{
                    cout << "(Drink Type) Value is out of scope: " << input_buffer << endl;
                }
            }
        }
    }

    /**
     * This method prompts the user for a sort selection in an interactive session
     * @precondition  (The instance of the object exists)
     * @postcondition (The drink sort is selected)
     */
    void AMGVending::PromptDrinkSort(){
        while(!AMGSystem::IsDigit(input_buffer) || input_buffer == ""){
            cout << "Sorts:" << endl;
            for(int i = 0; i < drink->GetSorts().size(); i++){
                cout << "\t* " << (i + 1) << ": " << drink->GetSorts()[i] << endl;
            }
            cout << "Option: ";
            cin >> input_buffer;
            if(input_buffer == "#"){
                AMGSystem::ExitProgram();
            }
            if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
                if(stoi(input_buffer) - 1 < drink->GetSorts().size()){
                    SetDrinkSort(drink->GetSorts()[stoi(input_buffer) - 1]);
                }
                else{
                    cout << "(Drink Sort) Value is out of scope: " << input_buffer << endl;
                }
            }
        }
    }

    /**
     * This method prompts the user for condiment selections in an interactive session
     * @precondition  (The instance of the object exists)
     * @postcondition (The condiments are added to the order)
     */
    void AMGVending::PromptCondiments(){
        for(int i = 0; i < drink_condiments.size(); i++){
            cout << "Would you like " << drink_condiments[i] << "? ";
            cin >> input_buffer;
            if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::BOOL)){
                input_buffer = "";
                while(input_buffer == ""){
                    cout << "How many servings would you like?: ";
                    cin >> input_buffer;
                    if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
                        if(stoi(input_buffer) <= condiment_limit){
                            // Milk
                            if(i == 0){
                                drink->AddCondiment(new CondimentMilk(stoi(input_buffer)));
                            }
                            // Sugar
                            else if(i == 1){
                                drink->AddCondiment(new CondimentSugar(stoi(input_buffer)));
                            }
                        }
                        else{
                            cout << "(Condiment Quantity) Value is out of scope: " << input_buffer << endl;
                            input_buffer = "";
                        }
                    }
                    else{
                        input_buffer = "";
                    }
                }
            }
        }
    }

    /**
     * This method prints the options in an interactive session
     * @precondition  (The instance of the object exists)
     * @postcondition (The drink order is built)
     */
    void AMGVending::PrintMenu(){
        input_buffer = "";

        cout << "Welcome to AMGVending" << endl;
        PromptDrinkType();
        input_buffer = "";
        PromptDrinkSort();
        input_buffer = "";
        cout << "Any condiments? (1: Yes, 2: No): ";
        cin >> input_buffer;

        
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::BOOL)){
            input_buffer = "";
            PromptCondiments();
        }
    }

    /**
     * This method performs the actual operation (ie. dispensing the drink)
     * @precondition  (The instance of the object exists)
     * @postcondition (The drink is dispensed)
     */
    void AMGVending::RunOperation(){
        if(drink != nullptr){
            drink->Brew();
            Dispense();
        }
        else{
            cout << "Drink is not of valid type..." << endl;
        }
    }

    /**
     * This method dispenses the drink
     * @precondition  (The instance of the object exists)
     * @postcondition (The drink is given to the patron.)
     */
    void AMGVending::Dispense(){
        cout << "Dispensing drink::" << drink->ToString() << endl;
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGVending::~AMGVending(){
        delete drink; // Remove the drink object from memory
    }

    /**
     * This method sets the mode to batchable
     * @param a Value to set for the flag
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is set)
     */
    void AMGVending::SetBatchable(bool a){
        batchable = a;
    }

    /**
     * This method retrieves the batchable flag
     * @return        (Value of the flag)
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is returned)
     */
    bool AMGVending::GetBatchable(){
        return batchable;
    }

    /**
     * This method is the main entry to the controller and prepares the session
     * @precondition  (The instance of the object exists)
     * @postcondition (The patron is prompted or the operations are ran in batch mode)
     */
    void AMGVending::Run(){
        if(batchable){
            RunBatchMode();
        }
        else{
            RunInteractive();
        }
    }
}
