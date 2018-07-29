#include "amgbattleshipboard.h"

namespace amgbattleship {

    /**
     * This method submits a new shot
     * @param a Coordinates of new shot
     * @param b Opponents data, strictly for statistics
     * @precondition  (The instance of the object must exist)
     * @postcondition (Data is displayed to the player)
     */
    void AMGBattleshipBoard::SubmitAttack(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipBoard> b) {
        // Build request
        shared_ptr<AMGBattleshipTarget> new_request(new AMGBattleshipTarget(a, this->data, b->GetData()));
        
        // Bundle request into a command
        shared_ptr<AMGShootTarget> new_command(new AMGShootTarget(new_request));
        shared_ptr<AMGBattleshipBroker> touret(new AMGBattleshipBroker());
        touret->AddTarget(new_command);
        
        // Submit command
        touret->ExecuteAttacks();
                                                    
        if(this->data->WasShot()) {
            cout << "HIT!" << endl;
        }
        else {
            cout << "MISS!" << endl;
        }

    }
    
    /**
     * This method prints game statistics for the player
     * @param opponent_data Opponents data, strictly for statistics
     * @precondition  (The instance of the object must exist)
     * @postcondition (Data is displayed to the player)
     */
	void AMGBattleshipBoard::PrintHeader(shared_ptr<AMGBattleshipData> opponent_data){
        // Print basic details
        cout << "Shots taken: " << this->data->GetPlayerShots().size() << ", Ships left: " << this->data->GetShipsLeft() << endl;
	}

    /**
     * This method creates the ships that will be on the board
     * @precondition  (The instance of the object must exist)
     * @postcondition (The ships are added for the players)
     */
    void AMGBattleshipBoard::GenerateShips() {
        for(int i = 0; this->data->GetShipCount() < this->GetShipCount(); i++){
            srand(time(NULL));
            int a = rand() % this->board_width;
            int b = rand() % this->board_height;
            this->data->AddShip(shared_ptr<AMGLocation>(new AMGLocation(a, b)));
        }
    }

    
    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGBattleshipBoard::AMGBattleshipBoard() {
		this->board_width = 5;
		this->board_height = 5;
		this->ship_count = 3;
        this->data = shared_ptr<AMGBattleshipData>(new AMGBattleshipData());
        this->data->SetShipCount(this->ship_count);
        this->GenerateShips();
	}

    /**
     * This is the common constructor.
	 * @param a Board height
	 * @param b Board width
	 * @param c Ship count
     * @param d Player number
     * @postcondition (A new instance of the object has been created.)
     */
	AMGBattleshipBoard::AMGBattleshipBoard(int a, int b, int c, int d) {
		if(c < a && c < b){
			this->board_width = a;
			this->board_height = b;
			this->ship_count = c;
            this->data = shared_ptr<AMGBattleshipData>(new AMGBattleshipData(d));
            this->GenerateShips();
		}
        else {
            cout << "Ship count cannot be larger than the board size..." << endl;
        }
	}

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
	AMGBattleshipBoard::~AMGBattleshipBoard() {
	}

    /**
     * This method sets the value of the board height
     * @param a Board height
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
	void AMGBattleshipBoard::SetBoardHeight(int a) {
		this->board_height = a;
	}

    /**
     * This method sets the value of the board width
     * @param a Board width
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
	void AMGBattleshipBoard::SetBoardWidth(int a) {
		this->board_width = a;
	}

    /**
     * This method sets the value of the ship count
     * @param a Number of ships on the board
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
	void AMGBattleshipBoard::SetShipCount(int a) {
		if(this->board_height > a && this->board_width > a){
			this->ship_count = a;
            this->data->SetShipCount(this->ship_count);
            this->GenerateShips(); // Regenerate ships
		}
		else {
			cout << "Ship count cannot be larger than the board size..." << endl;
		}
	}
    
    /**
     * This method retrieves the players data
     * @return Data
     * @precondition  (The instance of the object must exist)
     * @postcondition (The data is returned)
     */
    shared_ptr<AMGBattleshipData> AMGBattleshipBoard::GetData() {
        return this->data;
    }

    /**
     * This method gets the value of the board height
     * @return Board height
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	int AMGBattleshipBoard::GetBoardHeight() {
		return this->board_height;
	}

    /**
     * This method gets the value of the board width
     * @return Board width
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	int AMGBattleshipBoard::GetBoardWidth() {
		return this->board_width;
	}

    /**
     * This method gets the value of the ship count
     * @return Ship count
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	int AMGBattleshipBoard::GetShipCount() {
		return this->ship_count;
	}

	/**
	 * This method displays the objects on the board in the context of the current player
	 * @precondition  (The instance of the object must exist)
     * @postcondition (The board is displayed)
	 * @todo Include the display in the user specific client instance
	 * @todo Add a check if the ship was sunk, meaning all locations for the ship were hit
     */
	void AMGBattleshipBoard::PrintBoard(shared_ptr<AMGBattleshipData> opponent_data) {
        vector<shared_ptr<AMGLocation> > temp_shots = opponent_data->GetPlayerShots();
        vector<shared_ptr<AMGShip> > temp_ships = this->data->GetPlayerShips();
        int temp_ships_left = this->data->GetShipsLeft();
		int temp_shots_count = this->data->GetPlayerShots().size();
        
        // Plot map
		for(int i = 0; i < this->board_height; i++){
			if(i == 0){
            	for(int j = 0; j < this->board_width * 16; j++){
                	cout << "_";
            	}
			}

			cout << endl << endl;

			for(int j = 0; j < this->board_width; j++){
				if(j == 0){
					cout << "|";
				}
				cout << "\t";
				if(this->data->AlreadyShot(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_shots) && !this->data->IsLocationHit(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_ships)){
					cout << IS_SHOT_GRAPHIC;
				}
				else if(this->data->IsLocationHit(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_ships) && this->data->AlreadyShot(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_shots)){
					cout << IS_HIT_GRAPHIC;
				}
				else {
					cout << IS_WATER_GRAPHIC;
				}
			
				// Let the current player know if they have a ship at the location
				if(this->data->ShipAtLocation(shared_ptr<AMGLocation>(new AMGLocation(j,i)))){
					cout << " (S)";
				}
				cout << "\t|";
			}
			cout << endl;

			for(int j = 0; j < this->board_width * 16; j++){
                cout << "_";
            }
			cout  << endl;
		}

		cout << "Player " << opponent_data->GetPlayerNumber() << " 's shots:" << endl;
		for(int i = 0; i < temp_shots.size(); i++){
			cout << temp_shots[i]->ToString() << endl;
	 	}
	}
}
