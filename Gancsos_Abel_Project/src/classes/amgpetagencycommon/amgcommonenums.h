#ifndef __AMGCOMMONENUMS_H_INCLUDED
#define __AMGCOMMONENUMS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

namespace amgpetagencycommon{

    enum class GENDER {
        NONE,
        MALE,
        FEMALE
    };  

    enum class RACE {
        NONE,
        WHITE,
        BLACK,
        HISPANIC
    };

	enum class NATIONALITY {
		NONE,
		AMERICAN,
		ITALIAN,
		HUNGARIAN,
		ARMENIAN
	};

	enum class HAIR_COLOR {
		NONE,
		BROWN,
		BLACK,
		DARK_BROWN,
		WHITE,
		GREY,
	};

	enum class EYE_COLOR {
		NONE,
		GREEN,
		BLUE,
		BROWN,
		HAZEL
	};


	class AMGCommonEnums{

		public:
            const static GENDER ALL_GENDERS[3];
            static GENDER GetGender(int a);
            static string GetGenderName(GENDER a);
            const static NATIONALITY ALL_NATIONALITIES[5];
            static NATIONALITY GetNationality(int a);
            static string GetNationalityName(NATIONALITY a);
            const static HAIR_COLOR ALL_HAIR_COLORS[6];
            static HAIR_COLOR GetHairColor(int a);
            static string GetHairColorName(HAIR_COLOR a);
            const static EYE_COLOR ALL_EYE_COLORS[5];
            static EYE_COLOR GetEyeColor(int a);
            static string GetEyeColorName(EYE_COLOR a);
            const static RACE ALL_RACES[4];
            static RACE GetRace(int a);
            static string GetRaceName(RACE a);
	};
}

#endif
