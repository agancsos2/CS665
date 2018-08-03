#ifndef __AMGDOG_H_INCLUDED
#define __AMGDOG_H_INCLUDED

#include <iostream>
#include <vector>
#include "amgbreed.h"
#include "amganimal.h"
#include <memory>
using namespace std;

namespace amgpetagencycommon {

    /**
     * This class represents a dog in the animal kingdom
     */
    class AMGDog : public AMGAnimal {
        protected:
            GENDER gender;
            string name;
            float height;
            float weight;
			const static int adoption_time_seconds = 10;
			shared_ptr<AMGPerson> owner;
            shared_ptr<AMGBreed> breed;
        public:
            AMGDog();
            ~AMGDog();
            shared_ptr<AMGBreed> GetBreed();
            string ToString();
            string GetType();
            class DogBuilder;
            AMGDog(shared_ptr<DogBuilder> a);
			void Adopt(shared_ptr<AMGPerson> a, bool delay);
    };

    /**
     * This class helps build the dog object
     */
    class AMGDog::DogBuilder{
        public:
            GENDER gender;
            string name;
            float height;
            float weight;
			shared_ptr<AMGPerson> owner;
			shared_ptr<AMGBreed> breed;
            DogBuilder();
            ~DogBuilder();
            DogBuilder(string name);
            DogBuilder *WithGender(GENDER a);
            DogBuilder *WithHeight(float a);
            DogBuilder *WithWeight(float a);
            DogBuilder *WithBreed(shared_ptr<AMGBreed> a);
        	shared_ptr<AMGDog> Build();
    };
}

#endif

