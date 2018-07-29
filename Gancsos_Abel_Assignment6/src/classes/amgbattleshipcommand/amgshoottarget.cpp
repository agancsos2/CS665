#include "amgshoottarget.h"

namespace amgbattleshipcommand {

    /**
     * This is the default constructor
     * @postcondition (A new instance of the object has been created.)
     */
    AMGShootTarget::AMGShootTarget(){
    }

	/**
	 * This is the common constructor
	 * @param a Target or request
     * @postcondition (A new instance of the object has been created.)
	 */
	AMGShootTarget::AMGShootTarget(shared_ptr<AMGBattleshipTarget> a) {
        this->target = a;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGShootTarget::~AMGShootTarget() {
    }

    /**
     * This method performs the actual attack
     * @precondition  (An instance of the object exists)
     * @postcondition (A attack is performed.)
     */
	void AMGShootTarget::Execute() {
        this->target->Execute();
	}
}
