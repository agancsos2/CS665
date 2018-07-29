#include "amgbattleshiptarget.h"

namespace amgbattleshipcommand {

    /**
     * This is the default constructor
     * @postcondition (A new instance of the  object is created)
     */
	AMGBattleshipTarget::AMGBattleshipTarget() {
        this->location = shared_ptr<AMGLocation>(new AMGLocation(0,0));
	}

    /**
     * This is the common constructor
	 * @param a New target to shoot at
	 * @param b Player's information
     * @param c Opponent's data
     * @postcondition (A new instance of the  object is created)
     */
	AMGBattleshipTarget::AMGBattleshipTarget(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipData> b, shared_ptr<AMGBattleshipData> c) {
		this->location = a;
		this->player_data = b;
        this->opponent_data = c;
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
    void AMGBattleshipTarget::Execute() {
		this->player_data->AddShot(this->location, opponent_data);
	}
}
