#ifndef __AMGPERSONBUILDER_H_INCLUDED
#define __AMGPERSONBUILDER_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "../../amgpetagencycommon/amgpetagencycommon_all.h"
using namespace std;
using namespace amgpetagencycommon;

namespace amgpersonbuilder {
    
    /**
	 * This class helps configure a person
	 */
	class AMGPersonBuilder {
		protected:
            shared_ptr<AMGPerson> product;
		public:
			AMGPersonBuilder();
			~AMGPersonBuilder();
			virtual void SetGender(GENDER a) = 0;
			virtual void SetRace(RACE a) = 0;
			virtual void SetAge(int a) = 0;
			virtual void SetHairColor(HAIR_COLOR a) = 0;
			virtual void SetEyeColor(EYE_COLOR a) = 0;
			virtual void SetNationality(NATIONALITY a) = 0;
			virtual void SetWeight(float a) = 0;
			virtual void SetHeight(float a) = 0;
			virtual void SetWaistSize(int a) = 0;
			AMGPersonBuilder(string first, string last);
			virtual shared_ptr<AMGPerson> Build() = 0;
	};
}
#endif