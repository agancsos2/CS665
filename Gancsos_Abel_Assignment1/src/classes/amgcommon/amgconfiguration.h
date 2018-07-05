#ifndef __AMGCONFIGURATION_H_INCLUDED__  
#define __AMGCONFIGURATION_H_INCLUDED__ 

#include <string>
#include <vector>
#include "amgsystem.h"
#include "amgstring.h"
using namespace std;

/**
 * This class offers custom system operations
 * @author  (Abel Gancsos)
 * @version (v. 1.0.0)
 */
class AMGConfiguration{
    private:
        string input_file;
    public:
        AMGConfiguration();
        ~AMGConfiguration();
        AMGConfiguration(string a);
		string LookupKey(string a);
        void SetInputFile(string a);
        string GetInputFile();
};

#endif

