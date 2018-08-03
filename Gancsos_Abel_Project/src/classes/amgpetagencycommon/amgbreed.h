#ifndef __AMGBREED_H_INCLUDED
#define __AMGBREED_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

namespace amgpetagencycommon {

	/**
	 * This class represents an animal breed
	 */
	class AMGBreed {
		protected:
			shared_ptr<AMGBreed> mother_breed;
			shared_ptr<AMGBreed> father_breed;
			string name;
		public:
			AMGBreed();
			~AMGBreed();
			AMGBreed(string name);
			void SetFatherBreed(shared_ptr<AMGBreed> a);
			void SetMotherBreed(shared_ptr<AMGBreed> a);
			shared_ptr<AMGBreed> GetFatherBreed();
			shared_ptr<AMGBreed> GetMotherBreed();
			string GetName();
			string ToString();
	};
}

#endif
