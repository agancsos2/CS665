#ifndef __AMGPERSON_H_INCLUDED
#define __AMGPERSON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "amgcommonenums.h"
#include "../amgcommon/amgcommon_all.h"
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
            string GetFirstName();
            string GetLastName();
			void SetFirstName(string a);
			void SetLastName(string a);
			string ToString();
			GENDER GetGender();
			RACE GetRace();
			int GetAge();
			HAIR_COLOR GetHairColor();
			EYE_COLOR GetEyeColor();
			NATIONALITY GetNationality();
			float GetWeight();
			float GetHeight();
			int GetWaistSize();
			void SetGender(GENDER a);
			void SetRace(RACE a);
			void SetAge(int a);
			void SetHairColor(HAIR_COLOR a);
			void SetEyeColor(EYE_COLOR a);
			void SetNationality(NATIONALITY a);
			void SetWeight(float a);
			void SetHeight(float a);
			void SetWaistSize(int a);
	};
}

#endif
