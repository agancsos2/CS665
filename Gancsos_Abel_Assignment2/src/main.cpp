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
#include "classes/amgdispatch/amgdispatch_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgdispatch;

/**
 * This method is the main entry point from the command-line
 * @precondition  (Utility exists on a Windows/non-Windows environment)
 * @postcondition (Utility is started)
 */
int main(int argc, char **argv) {

	srand(time(NULL));

	AMGDispatch *session = new AMGDispatch();
	
	session->Run();
	delete session;
	AMGSystem::ExitProgram();
	
	return 0;
}
