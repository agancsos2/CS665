#ifndef __AMGTRACER_H_INCLUDED__  
#define __AMGTRACER_H_INCLUDED__ 

#include <string>
#include <vector>
#include <ctime>
#include "amgsystem.h"
#include "amgstring.h"
using namespace std;

namespace amgcommon{
	/**
 	 * This class is meant to help log information to both an output file and the console
 	 */
	class AMGTracer {
		private:
			string output_file;
		public:
			AMGTracer();
			AMGTracer(string a);
			~AMGTracer();
			void SetOutputFile(string a);
			void Trace(string a, bool print);
	};
}

#endif
