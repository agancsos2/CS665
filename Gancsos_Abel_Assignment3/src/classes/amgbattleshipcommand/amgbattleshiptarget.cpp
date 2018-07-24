#include "amgbattleshiptarget.h"

namespace amgbattleshipcommand {

    /**
     * This is the default constructor
     * @postcondition (A new instance of the  object is created)
     */
	AMGBattleshipTarget::AMGBattleshipTarget() {
        this->location = shared_ptr<AMGLocation>(new AMGLocation(0,0));
        this->board = shared_ptr<AMGBattleshipBoard>(new AMGBattleshipBoard());
	}

    /**
     * This is the common constructor
	 * @param a New target to shoot at
	 * @param b Board information
     * @postcondition (A new instance of the  object is created)
     */
	AMGBattleshipTarget::AMGBattleshipTarget(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipBoard> b) {
		this->location = a;
		this->board = b;
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGBattleshipTarget::~AMGBattleshipTarget() {
	}

    /**
     * This method performs the command operations
	 * @precondition  (An instance of the object must exist)
     * @postcondition (The shot has been taken and the board is updated)
     */
    void AMGBattleshipTarget::Shoot() {
		this->board->AddShot(this->location);
	}
}
