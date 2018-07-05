/**
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Results needed for the project are displayed)
 */

#include <iostream>
#include <vector>
#include "classes/amgcommon/amgcommon_all.h"
#include "classes/amgvending/amgvending_all.h"
using namespace std;

/**
 * This method is the main entry point from the command-line
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Utility is started)
 */
int main(int argc, char **argv) {
	bool help = false;
	vector<DrinkCondiment *> temp_condiments;
	AMGVending *session = new AMGVending();

	// Configure environment
	if((argc - 1) > 0) {
		// Iterate through the command-line arguments to setup and run the session
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-drink"){
				session->SetBatchable(true);
				session->SetDrinkType(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-sort"){
				session->SetBatchable(true);
				session->SetDrinkSort(string(argv[i + 1]));
            }
			else if(string(argv[i]) == "-condiments"){
				session->SetBatchable(true);
				vector<string> condiments = AMGString(string(argv[i + 1])).Split(",");
				for(int i = 0; i < condiments.size(); i++){
					if(AMGString(condiments[i]).ToLowerCase() == "sugar"){
						temp_condiments.push_back(new CondimentSugar());
					}
					else if(AMGString(condiments[i]).ToLowerCase() == "milk"){
						temp_condiments.push_back(new CondimentMilk());
					}
					else{
						cout << "Condiment is not valid: " << condiments[i] <<  endl; 
					}
				}
            }
			else if(string(argv[i]) == "-amount"){
				session->SetBatchable(true);
				vector<string> amount_values = AMGString(argv[i + 1]).Split(",");
				if(amount_values.size() == temp_condiments.size()){

					// Just set the values regardless of the amount.  Validation will be done later.
					for(int i = 0; i < amount_values.size(); i++){
						if(AMGVendingHelpers::ValidateInput(amount_values[i], INPUT_TYPES::NUMBER)){
							temp_condiments[i]->SetQuantity(stoi(amount_values[i]));
						}
						else{
							cout << "Amount value is not a digit: " << amount_values[i] << endl;
						}					
					}
				}
				else{
					cout << "Amount value list does not match condiments list count...." << endl;
				}
            }
		}
		session->AddCondiments(temp_condiments);
	}

	// Print help menu
	if(help){
		AMGVendingHelpers::HelpMenu();
	}
	
	// Run controller 
	else{
		session->Run();
	}

	delete session;

	// Exit program
	if(!help){
		AMGVendingHelpers::ExitProgram();
	}

	return 0;
}
