#ifndef __AMGDOGBUILDER_H_INCLUDED
#define __AMGDOGBUILDER_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "amganimalbuilder.h"
using namespace std;
using namespace amgpetagencycommon;

namespace amganimalbuilder {

    
    /**
     * This class helps build the dog object
     */
    class AMGDogBuilder : public AMGAnimalBuilder{
        private:
            shared_ptr<AMGAnimal> product;
        public:
            AMGDogBuilder();
            ~AMGDogBuilder();
            AMGDogBuilder(string name);
            void SetGender(GENDER a);
            void SetOwner(shared_ptr<AMGPerson> a);
            void SetHeight(float a);
            void SetWeight(float a);
            void SetBreed(shared_ptr<AMGBreed> a);
        	shared_ptr<AMGAnimal> Build();
    };
}
#endif