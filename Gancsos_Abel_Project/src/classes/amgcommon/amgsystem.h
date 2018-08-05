#ifndef __AMGSYSTEM_H_INCLUDED__  
#define __AMGSYSTEM_H_INCLUDED__ 

#include <iostream>
#if !defined(WIN32) && !defined(_WIN32) && !defined(__WIN32) && !defined(__CYGWIN__)
    #include <unistd.h>
#else
    #include <windows.h>
#endif
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include "amgcommon_all.h"
using namespace std;

namespace amgcommon{
    enum class INPUT_TYPES {
        STRING,
        NUMBER,
        BOOL
    };
    

	/**
 	 * This class offers custom system operations
 	 * @author  (Abel Gancsos)
 	 * @version (v. 1.0.0)
 	 */
	class AMGSystem{
		private:
        	string source;
        	string target;
		public:
			AMGSystem();
			~AMGSystem();
			AMGSystem(string src);
			AMGSystem(string src,string tar);
			string ReadFile();
			void WriteFile(string data);
			void SetSource(string a);
			void SetTarget(string a);
			string GetSource();
			string GetTarget();
			bool FileExists(string path);
			static void Sleeper(int seconds);
            static void ExitProgram();
            static bool IsDigit(string a);
            static bool ValidateInput(string a, INPUT_TYPES b);
	};
}

#endif
