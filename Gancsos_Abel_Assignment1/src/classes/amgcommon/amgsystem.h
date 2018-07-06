#ifndef __AMGSYSTEM_H_INCLUDED__  
#define __AMGSYSTEM_H_INCLUDED__ 

#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
using namespace std;

namespace amgcommon{
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
	};
}

#endif
