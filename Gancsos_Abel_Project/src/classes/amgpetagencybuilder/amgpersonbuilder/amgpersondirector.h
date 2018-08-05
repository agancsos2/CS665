#ifndef __AMGPERSONDIRECTOR_H_INCLUDED
#define __AMGPERSONDIRECTOR_H_INCLUDED

#include <iostream>
#include <vector>
#include <memory>
#include "../../amgpetagencycommon/amgpetagencycommon_all.h"
#include "amgpersonbuilder.h"
#include "amgcustomerbuilder.h"
using namespace std;
using namespace amgpetagencycommon;

namespace amgpersonbuilder {

    
    /**
     * This class helps build the dog object
     */
    class AMGPersonDirector {
        private:
            shared_ptr<AMGPersonBuilder> builder;
        public:
            AMGPersonDirector();
            ~AMGPersonDirector();
            AMGPersonDirector(shared_ptr<AMGPersonBuilder> a);
            shared_ptr<AMGPerson> Build();
    };
}
#endif