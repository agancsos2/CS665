#ifndef __AMGANIMAL_H_INCLUDED
#define __AMGANIMAL_H_INCLUDED

#include <iostream>
#include <vector>
#include "amgbreed.h"
#include <memory>
#include "amgcommonenums.h"
#include "amgperson.h"
using namespace std;

namespace amgpetagencycommon {

	/**
	 * This class represents a generic animal
	 */
	class AMGAnimal {
		protected:
			GENDER gender;
			string name;
			float height;
			float weight;
			const static int adoption_time_seconds = 0;;
			shared_ptr<AMGPerson> owner;
		public:
			AMGAnimal();
			virtual ~AMGAnimal() = 0;
			virtual string ToString() = 0;
			virtual string GetType() = 0;
			virtual void Adopt(shared_ptr<AMGPerson> a, bool delay) = 0;
	};
}

#endif
