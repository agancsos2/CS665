/**
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Results needed for the project are displayed)
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "classes/amgcommon/amgcommon_all.h"
#include "classes/amgbattleship/amgbattleship_all.h"
using namespace std;
using namespace amgbattleship;
using namespace amgcommon;

/**
 * This method is displayed as a help menu
 * @precondition  (Utility has been with the help switch)
 * @postcondition (Details of the utility are displayed in the system console)
 */
void HelpMenu() {
	cout << AMGString("").PadLeft(80,"=") << endl;
    cout << "* Name   : AMGBattleship" << endl;
    cout << "* Author : Abel Gancsos" << endl;
    cout << "* Version: v. 1.0.0" << endl;
   	cout << "* Flags:" << endl;
	cout << "\t* -height : Height of the board (default: 5)" << endl;
	cout << "\t* -width  : Width of the board (default: 5)" << endl;
	cout << "\t* -count  : Number of ships on the board (default: 3)" << endl;
    cout << AMGString("").PadLeft(80,"=") << endl;
}

/**
 * This method is the main entry point from the command-line
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Utility is started)
 */
int main(int argc, char **argv) {

	bool help = false;
	AMGBattleship *session = new AMGBattleship();
	srand(time(NULL));

	// Read in parameters to configure the session
	if((argc - 1) > 0) {
		for(int i = 0; i < argc; i++){
			if(string(argv[i]) == "-h"){
				help = true;
			}
			else if(string(argv[i]) == "-height"){
                if(AMGSystem::ValidateInput(string(argv[i + 1]), INPUT_TYPES::NUMBER)){
					session->SetBoardHeight(stoi(string(argv[i + 1])));
				}
				else {
					cout << argv[i + 1] << " was not a valid format" << endl;
				}
            }
            else if(string(argv[i]) == "-width"){
                if(AMGSystem::ValidateInput(string(argv[i + 1]), INPUT_TYPES::NUMBER)){
                    session->SetBoardWidth(stoi(string(argv[i + 1])));
                }
                else {
                    cout << argv[i + 1] << " was not a valid format" << endl;
                }
            }
            else if(string(argv[i]) == "-count"){
                if(AMGSystem::ValidateInput(string(argv[i + 1]), INPUT_TYPES::NUMBER)){
                    session->SetShipCount(stoi(string(argv[i + 1])));
                }
                else {
                    cout << argv[i + 1] << " was not a valid format" << endl;
                }
            }
		}
	}

	if(help){
		HelpMenu();
	}
	else{
		session->Run();
	}

	delete session;

	AMGSystem::ExitProgram();

	return 0;
}
