#ifndef __AMGCUSTOMERBUILDER_H_INCLUDED
#define __AMGCUSTOMERBUILDER_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "amgpersonbuilder.h"
using namespace std;
using namespace amgpetagencycommon;

namespace amgpersonbuilder {
    
    /**
	 * This class helps configure a person
	 */
	class AMGCustomerBuilder : public AMGPersonBuilder {
		private:
            shared_ptr<AMGPerson> product;
		public:
			AMGCustomerBuilder();
			~AMGCustomerBuilder();
			AMGCustomerBuilder(string first, string last);
            void SetGender(GENDER a);
			void SetRace(RACE a);
			void SetAge(int a);
			void SetHairColor(HAIR_COLOR a);
			void SetEyeColor(EYE_COLOR a);
			void SetNationality(NATIONALITY a);
			void SetWeight(float a);
			void SetHeight(float a);
			void SetWaistSize(int a);
			shared_ptr<AMGPerson> Build();
	};
}
#endif