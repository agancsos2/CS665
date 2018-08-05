#ifndef __AMGANIMALBUILDER_H_INCLUDED
#define __AMGANIMALBUILDER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../../amgcommon/amgcommon_all.h"
#include "../../amgpetagencycommon/amgpetagencycommon_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgpetagencycommon;

namespace amganimalbuilder{

	/**
	 * This class helps configure a person
	 */
	class AMGAnimalBuilder {
        protected:
            shared_ptr<AMGAnimal> product;
		public:
            AMGAnimalBuilder();
            virtual ~AMGAnimalBuilder() = 0;
			virtual shared_ptr<AMGAnimal> Build() = 0;
			virtual void SetGender(GENDER a) = 0;
            virtual void SetOwner(shared_ptr<AMGPerson> a) = 0;
            virtual void SetHeight(float a) = 0;
            virtual void SetWeight(float a) = 0;
            virtual void SetBreed(shared_ptr<AMGBreed> a) = 0;
	};
}

#endif