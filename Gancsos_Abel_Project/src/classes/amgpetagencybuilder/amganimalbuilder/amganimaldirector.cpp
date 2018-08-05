#include "amganimaldirector.h"

namespace amganimalbuilder {

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGAnimalDirector::AMGAnimalDirector() {

    }

    /**
     * This is the default deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGAnimalDirector::~AMGAnimalDirector() {

    }

    /**
     * This is the common constructor
     * @param a The specific class builder to build
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
    AMGAnimalDirector::AMGAnimalDirector(shared_ptr<AMGAnimalBuilder> a) {
        this->builder = a;
    }

    /**
     * This method constructs a new instance of the class
     * @precondition  (The instance of the object must exist)
     * @postcondition (The instance of the builder class is created)
     */
    shared_ptr<AMGAnimal> AMGAnimalDirector::Build() {
        return this->builder->Build();
    }
}