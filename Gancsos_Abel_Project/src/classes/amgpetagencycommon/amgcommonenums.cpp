#include "amgcommonenums.h"

namespace amgpetagencycommon {
    const GENDER AMGCommonEnums::ALL_GENDERS[3] = {GENDER::NONE, GENDER::MALE, GENDER::FEMALE};
    GENDER AMGCommonEnums::GetGender(int a) {
        return AMGCommonEnums::ALL_GENDERS[a];
    }
    string AMGCommonEnums::GetGenderName(GENDER a){
        switch(a){
            case GENDER::NONE:
                return "None";
            case GENDER::MALE:
                return "Male";
            case GENDER::FEMALE:
                return "Female";
            default:
                return "None";
        }
    }
    const NATIONALITY AMGCommonEnums::ALL_NATIONALITIES[5] = {NATIONALITY::NONE,NATIONALITY::AMERICAN,NATIONALITY::ITALIAN,NATIONALITY::HUNGARIAN,NATIONALITY::ARMENIAN};
    NATIONALITY AMGCommonEnums::GetNationality(int a) {
        return AMGCommonEnums::ALL_NATIONALITIES[a];
    }
    string AMGCommonEnums::GetNationalityName(NATIONALITY a){
        switch(a){
            case NATIONALITY::NONE:
                return "None";
            case NATIONALITY::AMERICAN:
                return "American";
            case NATIONALITY::ITALIAN:
                return "Italian";
            case NATIONALITY::HUNGARIAN:
                return "Hungarian";
            case NATIONALITY::ARMENIAN:
                return "Armenian";
            default:
                return "None";
        }
    }
    
    const HAIR_COLOR AMGCommonEnums::ALL_HAIR_COLORS[6] = {HAIR_COLOR::NONE,HAIR_COLOR::BROWN,HAIR_COLOR::BLACK,HAIR_COLOR::DARK_BROWN,HAIR_COLOR::WHITE,HAIR_COLOR::GREY};
    HAIR_COLOR AMGCommonEnums::GetHairColor(int a) {
        return AMGCommonEnums::ALL_HAIR_COLORS[a];
    }
    string AMGCommonEnums::GetHairColorName(HAIR_COLOR a){
        switch(a){
            case HAIR_COLOR::NONE:
                return "None";
            case HAIR_COLOR::BROWN:
                return "Brown";
            case HAIR_COLOR::BLACK:
                return "Black";
            case HAIR_COLOR::DARK_BROWN:
                return "Dark Brown";
            case HAIR_COLOR::WHITE:
                return "White";
            case HAIR_COLOR::GREY:
                return "Grey";
            default:
                return "None";
        }
    }
    
    const EYE_COLOR AMGCommonEnums::ALL_EYE_COLORS[5] = {EYE_COLOR::NONE,EYE_COLOR::GREEN,EYE_COLOR::BLUE,EYE_COLOR::BROWN,EYE_COLOR::HAZEL};
    EYE_COLOR AMGCommonEnums::GetEyeColor(int a) {
        return AMGCommonEnums::ALL_EYE_COLORS[a];
    }
    string AMGCommonEnums::GetEyeColorName(EYE_COLOR a){
        switch(a){
            case EYE_COLOR::NONE:
                return "None";
            case EYE_COLOR::BROWN:
                return "Brown";
            case EYE_COLOR::GREEN:
                return "Green";
            case EYE_COLOR::BLUE:
                return "Blue";
            case EYE_COLOR::HAZEL:
                return "Hazel";
            default:
                return "None";
        }
    }

    const RACE AMGCommonEnums::ALL_RACES[4] = {RACE::NONE, RACE::WHITE, RACE::BLACK, RACE::HISPANIC};
    RACE AMGCommonEnums::GetRace(int a) {
        return AMGCommonEnums::ALL_RACES[a];
    }
    string AMGCommonEnums::GetRaceName(RACE a){
        switch(a){
            case RACE::NONE:
                return "None";
            case RACE::WHITE:
                return "White";
            case RACE::BLACK:
                return "Black";
            case RACE::HISPANIC:
                return "Hispanic";
            default:
                return "None";
        }
    }
}
