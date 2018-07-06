#ifndef __AMGVENDINGHELPERS_H_INCLUDED__  
#define __AMGVENDINGHELPERS_H_INCLUDED__ 

#include <iostream>
#include <vector>
#include <string>
#include "../amgcommon/amgcommon_all.h"
using namespace std;
using namespace amgcommon;


namespace amgvending{
	enum class INPUT_TYPES {
		STRING,
		NUMBER,
		BOOL
	};

	/**
 	 * This class offers helper methods for the AMGVending "session" class
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
 	 */
	class AMGVendingHelpers {
		public:
			static void HelpMenu();
			static void ExitProgram();
			static bool IsDigit(string a);
			static bool ValidateInput(string a, INPUT_TYPES b);
	};
}

#endif
