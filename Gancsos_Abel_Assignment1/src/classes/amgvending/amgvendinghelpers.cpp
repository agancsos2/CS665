#include "amgvendinghelpers.h"
namespace amgvending {
    /**
     * This method is displayed as a help menu for non-interactive options
     * @precondition  (Utility has been with the help switch)
     * @postcondition (Details of the utility are displayed in the system console)
     */
    void AMGVendingHelpers::HelpMenu(){
        cout << AMGString("").PadLeft(80,"=") << endl;
        cout << "* Name   : AMGVending" << endl;
        cout << "* Author : Abel Gancsos" << endl;
        cout << "* Version: v. 1.0.0" << endl;
        cout << "* Flags:" << endl;
        cout << "  * -drink     : Type of drink" << endl;
        cout << "  ** Coffee" << endl;
        cout << "  ** Tea" << endl;
        cout << "  * -sort      : Subtype of the beverage" << endl;
        cout << "  ** Coffee:" << endl;
        cout << "  *** Espresso" << endl;
        cout << "  *** Americano" << endl;
        cout << "  *** Latte Macchiato" << endl;
        cout << "  ** Tea  : " << endl;
        cout << "  *** Black " << endl;
        cout << "  *** Green " << endl;
        cout << "  *** Yellow" << endl;
        cout << "  * -condiments: List of condiments to add" << endl;
        cout << "  ** Milk" << endl;
        cout << "  ** Sugar" << endl;
        cout << "  * -amount    : Quantity of the condiments to add (Max=3)" << endl;
        cout << AMGString("").PadLeft(80,"=") << endl;
    }
}
