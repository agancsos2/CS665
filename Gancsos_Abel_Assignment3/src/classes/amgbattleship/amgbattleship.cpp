#include "amgbattleship.h"

namespace amgbattleship {

    /**
     * This method creates the ships that will be on the board
     * @precondition  (The instance of the object must exist)
     * @postcondition (The ships are added for the players)
     */
	void AMGBattleship::GenerateShips() {
		for(int i = 1; i <= 2; i++){
			for(int j = 0; this->board->GetShipCount(i) < this->board->GetShipCount(); j++){
				int a = rand() % this->board->GetBoardWidth();
				int b = rand() % this->board->GetBoardHeight();
				this->board->AddShip(shared_ptr<AMGLocation>(new AMGLocation(a, b)), i);
			}
		}
	}

	/**
	 * This method prints the final scores
	 * @precondition  (The instance of the object must exist)
     * @postcondition (The prompt was displayed)
     */
	void AMGBattleship::PrintGameOver() {
		if(this->board->GetPlayer1ShipCount() > this->board->GetPlayer2ShipCount()){
            cout << "Player 1 WINS!!!" << endl;
        }
        else if(this->board->GetPlayer2ShipCount() > this->board->GetPlayer1ShipCount()){
            cout << "Player 2 WINS!!! " << endl;
        }
        else {
            cout << "Game ended in a tie!" << endl;
        }
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGBattleship::AMGBattleship() {	
		this->board = shared_ptr<AMGBattleshipBoard>(new AMGBattleshipBoard());
		this->current_player = 0;
		this->input_buffer = "";
	}

	/**
	 * This method prompts the current user for a location on the board to fire at
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The prompt was displayed)
	 */
	void AMGBattleship::PromptUser(){

		this->input_buffer = "";
		vector<string> pairs = AMGString(this->input_buffer).Split(",");
		while(this->input_buffer == ""){
			cout << "PLAYER" << this->current_player << " - Please select X,Y coordinates to target: ";
			cin >> this->input_buffer;

			// Forefeit
			if(this->input_buffer == "#"){
				this->board->Forfeit();
				PrintGameOver();
				AMGSystem::ExitProgram();
			}

			pairs = AMGString(this->input_buffer).Split(",");
	
			// Validate input
			if(pairs.size() == 2){
				for(int i = 0; i < pairs.size(); i++){
					if(!AMGSystem::ValidateInput(pairs[i], INPUT_TYPES::NUMBER)){
						cout << "Input was in an incorrect format(2).  Please try again..." << endl;
                		this->input_buffer = "";
                		continue;
					}
				}

				if(stoi(pairs[0]) > this->board->GetBoardWidth() - 1 || stoi(pairs[1]) > this->board->GetBoardHeight() - 1 ||
					stoi(pairs[0]) < 0 || stoi(pairs[1]) < 0){
					cout << "Coordinates are not within range of the map..." << endl;
					this->input_buffer = "";
					continue;
				}

                // Build request
				shared_ptr<AMGLocation> new_location(new AMGLocation(stoi(pairs[0]), stoi(pairs[1])));
				shared_ptr<AMGBattleshipTarget> new_request(new AMGBattleshipTarget(new_location, board));

				// Bundle request into a command
				shared_ptr<AMGShootTarget> new_command(new AMGShootTarget(new_request));
				shared_ptr<AMGBattleshipBroker> touret(new AMGBattleshipBroker());
				touret->AddTarget(new_command);
                
                // Submit command
				touret->ExecuteAttacks();
				
                if(this->board->WasShot()) {
                    cout << "HIT!" << endl;
                }
                else {
                    cout << "MISS!" << endl;
                }
			}
			else {
				cout << "Input was in an incorrect format(1).  Please try again..." << endl;
				this->input_buffer = "";
				continue;
			}
		}
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGBattleship::~AMGBattleship() {
	}

    /**
     * This method sets the value of the board height
     * @param a Board height
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
    void AMGBattleship::SetBoardHeight(int a) {
		this->board->SetBoardHeight(a);
	}

    /**
     * This method sets the value of the board width
     * @param a Board width
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
    void AMGBattleship::SetBoardWidth(int a) {
		this->board->SetBoardWidth(a);
	}

    /**
     * This method sets the value of the ship count
     * @param a Number of ships on the board
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
    void AMGBattleship::SetShipCount(int a) {
		this->board->SetShipCount(a);
	}

    /**
     * This method instantiates the game board and starts the interactive game play
     * @precondition  (The instance of the object must exist)
     * @postcondition (The game board has been initiated)
     */
    void AMGBattleship::Run() {

		this->GenerateShips();

		this->current_player = 0;
	
		// While both players have ships on the board	
		while(this->board->GetPlayer1ShipCount() > 0 && this->board->GetPlayer2ShipCount() > 0){
			// Set the next player
			switch(this->current_player) {
				case 0:
					this->current_player = 1;
					break;
				case 1:
					this->current_player = 2;
					break;
				case 2:
					this->current_player = 1;
					break;
			}
			this->board->SetCurrentPlayer(this->current_player);
			this->board->PrintHeader();
			this->board->PrintBoard();
            this->PromptUser();
			AMGSystem::Sleep(sleep_seconds);
			AMGSystem::Clear();
        }

		PrintGameOver();
	}
}
