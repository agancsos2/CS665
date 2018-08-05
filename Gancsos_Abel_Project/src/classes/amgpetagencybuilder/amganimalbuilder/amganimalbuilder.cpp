#include "amganimalbuilder.h"

namespace amganimalbuilder {
    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGAnimalBuilder::~AMGAnimalBuilder(){
    }

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGAnimalBuilder::AMGAnimalBuilder() {
        this->product = shared_ptr<AMGDog>(new AMGDog());
    }
}