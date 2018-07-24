#include "amgbattleshipbroker.h"

namespace amgbattleshipcommand {
    
    /**
     * This is the default constructor
     * @postcondition (A new instance of the  object is created)
     */
	AMGBattleshipBroker::AMGBattleshipBroker() {
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGBattleshipBroker::~AMGBattleshipBroker() {
        this->attacks.clear();
	}
    
    /**
     * This method adds a command to be executed
     * @param a Command to add
     * @precondition  (An instance of the object exists)
     * @postcondition (the command has been added)
     */
    void AMGBattleshipBroker::AddTarget(shared_ptr<AMGBattleshipCommand> a){
        this->attacks.push_back(a);
    }

    /**
     * This method performs the attacks
     * @precondition  (An instance of the object exists)
     * @postcondition (A attacks were performed.)
     */
	void AMGBattleshipBroker::ExecuteAttacks() {
		for(int i = 0; i < this->attacks.size(); i++){
            this->attacks[i]->Execute();
		}
		this->attacks.clear();
	}
}
