/**
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Results needed for the project are displayed)
 */

#include <iostream>
#include <vector>
#include <memory>
#include "classes/amgcommon/amgcommon_all.h"
#include "classes/amgpetagency/amgpetagency_all.h"
using namespace std;
using namespace amgpetagency;

/**
 * This method is the main entry point from the command-line
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Utility is started)
 */
int main(int argc, char **argv) {
	bool help = false;
	shared_ptr<AMGPetAgency> session(new AMGPetAgency());

	// Configure environment
	if((argc - 1) > 0) {
		// Iterate through the command-line arguments to setup and run the session
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-m"){
				session->SetBatchable(true);
				session->SetMode(string(argv[i + 1]));
			}
			else if(string(argv[i]) == "-row"){
				session->SetBatchable(true);
				session->SetValue(string(argv[i + 1]));
			}
		}
	}

	// Print help menu
	if(help){
		AMGPetAgencyHelpers::HelpMenu();
	}
	
	// Run controller 
	else{
		session->Run();
	}

	return 0;
}
