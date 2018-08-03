#ifndef __AMGPERSON_H_INCLUDED
#define __AMGPERSON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "amgcommonenums.h"
#include "../amgcommon/amgcommon_all.h"
#include <memory>
using namespace std;
using namespace amgcommon;

namespace amgpetagencycommon{

	/**
	 * This class represents a person
	 */
	class AMGPerson {
		protected:
			string first_name;
			string last_name;
			GENDER gender;
			RACE race;
			int age;
			HAIR_COLOR hair_color;
			EYE_COLOR eye_color;
			NATIONALITY nationality;
			float weight;
			float height;
			int waist_size;
		public:
			AMGPerson();
			~AMGPerson();
			class PersonBuilder;
            string GetFirstName();
            string GetLastName();
			string ToString();
			AMGPerson(PersonBuilder *builder);
	};

	/**
	 * This class helps configure a person
	 */
	class AMGPerson::PersonBuilder {
		public:
			string first_name;
            string last_name;
            GENDER gender;
            RACE race;
			int age;
            HAIR_COLOR hair_color;
            EYE_COLOR eye_color;
            NATIONALITY nationality;
            float weight;
            float height;
            int waist_size;
			PersonBuilder();
			~PersonBuilder();
			PersonBuilder *WithGender(GENDER a);
			PersonBuilder *WithRace(RACE a);
			PersonBuilder *WithAge(int a);
			PersonBuilder *WithHairColor(HAIR_COLOR a);
			PersonBuilder *WithEyeColor(EYE_COLOR a);
			PersonBuilder *WithNationality(NATIONALITY a);
			PersonBuilder *WithWeight(float a);
			PersonBuilder *WithHeight(float a);
			PersonBuilder *WithWaistSize(int a);
			PersonBuilder(string first, string last);
			shared_ptr<AMGPerson> Build();
	};
}

#endif
