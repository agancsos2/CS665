#ifndef __AMGDOG_H_INCLUDED
#define __AMGDOG_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "amgbreed.h"
#include "amganimal.h"
#include "amgperson.h"
using namespace std;

namespace amgpetagencycommon {

    
    /**
     * This class represents a dog in the animal kingdom
     */
    class AMGDog : public AMGAnimal {
        protected:
            const static int adoption_time_seconds = 5;
        public:
            AMGDog();
            shared_ptr<AMGBreed> GetBreed();
            string ToString();
            string GetType();
			void Adopt(shared_ptr<AMGPerson> a, bool delay);
            GENDER GetGender();
            string GetName();
            void SetName(string a);
            float GetHeight();
            float GetWeight();
            shared_ptr<AMGPerson> GetOwner();
            void SetGender(GENDER a);
            void SetOwner(shared_ptr<AMGPerson> a);
            void SetHeight(float a);
            void SetWeight(float a);
            void SetBreed(shared_ptr<AMGBreed> a);
    };
}

#endif