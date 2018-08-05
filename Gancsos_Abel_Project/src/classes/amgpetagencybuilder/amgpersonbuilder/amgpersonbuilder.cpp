#include "amgpersonbuilder.h"

namespace amgpersonbuilder {

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGPersonBuilder::~AMGPersonBuilder(){
    }

    /**
     * This is the default constructor
     * @precondition  (There is a need for a new instance of the class)
     * @postcondition (A new instance of the object is created)
     */
	AMGPersonBuilder::AMGPersonBuilder() {
        this->product = shared_ptr<AMGPerson>(new AMGPerson());
	}

	/**
	 * This method creates a builder object with the first and last names
	 * @param first First name of the person
	 * @param last Last name of the person
	 * @postcondition (A new instance of the builder is created)
	 */
     AMGPersonBuilder::AMGPersonBuilder(string first, string last){
        this->product = shared_ptr<AMGPerson>(new AMGPerson());
        this->product->SetFirstName(first);
        this->product->SetLastName(last);
	}
}
