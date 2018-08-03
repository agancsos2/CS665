#include "amgpetagencyhelpers.h"

namespace amgpetagency{
    /**
     * This method is displayed as a help menu for non-interactive options
     * @precondition  (Utility has been with the help switch)
     * @postcondition (Details of the utility are displayed in the system console)
     */
    void AMGPetAgencyHelpers::HelpMenu(){
        cout << AMGString("").PadLeft(80,"=") << endl;
        cout << "* Name   : AMGPetAgency" << endl;
        cout << "* Author : Abel Gancsos" << endl;
        cout << "* Version: v. 1.0.0" << endl;
        cout << "* Flags:" << endl;
		cout << " * -m : Appropriate numeric menu value for the operation to perform." << endl;
		cout << "  * 0  : Exit" << endl;
		cout << "  * 1  : List People" << endl;
		cout << "  * 2  : List Available Pets" << endl;
		cout << "  * 3  : List Adopted Pets" << endl;
        cout << "  * 4  : Adopt Pet" << endl;
        cout << "  * 5  : Return Pet" << endl;
        cout << AMGString("").PadLeft(80,"=") << endl;
    }
}

