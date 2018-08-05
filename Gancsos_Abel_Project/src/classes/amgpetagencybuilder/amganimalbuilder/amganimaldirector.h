#ifndef __AMGANIMALDIRECTOR_H_INCLUDED
#define __AMGANIMALDIRECTOR_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "../../amgpetagencycommon/amgpetagencycommon_all.h"
#include "amganimalbuilder.h"
#include "amgdogbuilder.h"
using namespace std;
using namespace amgpetagencycommon;

namespace amganimalbuilder {

    
    /**
     * This class helps build the dog object
     */
    class AMGAnimalDirector {
        private:
            shared_ptr<AMGAnimalBuilder> builder;
        public:
            AMGAnimalDirector();
            ~AMGAnimalDirector();
            AMGAnimalDirector(shared_ptr<AMGAnimalBuilder> a);
            shared_ptr<AMGAnimal> Build();
    };
}
#endif