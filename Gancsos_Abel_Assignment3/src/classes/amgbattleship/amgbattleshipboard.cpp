#include "amgbattleshipboard.h"

namespace amgbattleship {

	void AMGBattleshipBoard::PrintHeader(){
        vector<shared_ptr<AMGLocation> > temp_shots;
        vector<shared_ptr<AMGShip> > temp_ships;
        int temp_ships_left = 0;
        int temp_shots_count = 0;

        // Set temp collections
        switch(this->current_player) {
            case 1:
                temp_shots = this->player2_shots;
                temp_ships = this->player1_ships;
                temp_ships_left = this->player1_ships_left;
                temp_shots_count = this->player1_shots.size();
                break;
            case 2:
                temp_shots = this->player1_shots;
                temp_ships = this->player2_ships;
                temp_ships_left = this->player2_ships_left;
                temp_shots_count = this->player2_shots.size();
                break;
        }

        // Print basic details
        cout << "Shots taken: " << temp_shots_count << ", Ships left: " << temp_ships_left << endl;
	}

	/**
	 * This method adds a new shot to the current player's collection
	 * @param a Shot location
	 * @precondition  (An instance of the object must exist)
	 * @postcondition (The shot was added and the result is returned)
	 */
	void AMGBattleshipBoard::AddShot(shared_ptr<AMGLocation> a){
		bool hit = false;
		switch(current_player){
			case 1:
				this->player1_shots.push_back(a);
				hit = ShipAtLocation(a, player2_ships);
				if(hit) {
					this->player2_ships_left--;
				}
				break;
			case 2:
				this->player2_shots.push_back(a);
				hit = ShipAtLocation(a, player1_ships);
				if(hit){
					this->player1_ships_left--;
				}
				break;
		}
		is_shot =  hit;
	}

	/**
     * This method checks if the last shot was a hit
     * @return True if it was a hit, false if not
     * @precondition  (An instance of the object must exist)
     * @postcondition (The result is returned)
     */
    bool AMGBattleshipBoard::WasShot() {
		return is_shot;
	}

    /**
     * This method checks if the current player has a ship at the location
     * @param a Location to lookup
	 * @param b Collection to search
     * @return True if it was, false if not
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */
	bool AMGBattleshipBoard::ShipAtLocation(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b){
		for(int i = 0; i < b.size(); i++){
			for(int j = 0; j < b[i]->GetLocation().size(); j++){
				if(b[i]->GetLocation()[j]->Equals(a)){
					return true;
				}
			}
		}
		return false;
	}

	/** 
	 * This method returns the number of ships the player has
	 * @param a Player number
	 * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */
	int AMGBattleshipBoard::GetShipCount(int a){
        vector<shared_ptr<AMGShip> > temp_ships;

        // Set temp collections
        switch(a) {
            case 1:
                temp_ships = this->player1_ships;
                break;
            case 2:
                temp_ships = this->player2_ships;
                break;
        }
		return temp_ships.size();
	}

    /**
     * This method adds a ship to the given user
     * @param a Location to lookup
     * @param b Player number
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The ship is added to the player)
     */
    void AMGBattleshipBoard::AddShip(shared_ptr<AMGLocation> a, int b) {
        vector<shared_ptr<AMGShip> > temp_ships;

        // Set temp collections
        switch(b) {
            case 1:
                temp_ships = this->player1_ships;
                break;
            case 2:
                temp_ships = this->player2_ships;
                break;
        }

		if(! this->ShipAtLocation(a, temp_ships)){
        	switch(b){
            	case 1:
                	this->player1_ships.push_back(shared_ptr<AMGShip>(new AMGShip(a->GetXCoordinates(), a->GetYCoordinates())));
                	break;
            	case 2:
                	this->player2_ships.push_back(shared_ptr<AMGShip>(new AMGShip(a->GetXCoordinates(), a->GetYCoordinates())));
                	break;
			}
        }
    }
    
	/**
	 * This method checks if the location was hit	
	 * @param a Location to lookup
	 * @param b Collection to look through
	 * @return True if it was hit, false if not
	 * @precondition  (The instance of the objects must exist)
	 * @postcondition (The result of the lookup is returned)
	 */
	bool AMGBattleshipBoard::IsLocationHit(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b){
		for(int i = 0; i < b.size(); i++){
			for(int j = 0; j < b[i]->GetLocation().size(); j++){
				if(a->Equals(b[i]->GetLocation()[j])){
					return true;
				}
			}
		}
		return false;
	}
   
    /**
     * This method checks if the location was hit
     * @param a Location to lookup
     * @return True if it was hit, false if not
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */ 
    bool AMGBattleshipBoard::IsLocationHit(shared_ptr<AMGLocation> a) {
        switch(this->current_player){
            case 1:
                return this->IsLocationHit(a, this->player2_ships);
            case 2:
                return this->IsLocationHit(a, this->player1_ships);
        }
        return false;
    }
    
    
    /**
     * This method checks if the location was already shot at
     * @param a Location to lookup
     * @param b Collection to look through
     * @return True if it was, false if not
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */
    bool AMGBattleshipBoard::AlreadyShot(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGLocation> > b){
        for(int i = 0; i < b.size(); i++){
            if(a->Equals(b[i])){
                return true;
            }
        }
        return false;
    }

	/**
     * This method checks if the current player has a ship at the location
     * @param a Location to lookup
     * @return True if it was, false if not
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */
	bool AMGBattleshipBoard::ShipAtLocation(shared_ptr<AMGLocation> a){
        vector<shared_ptr<AMGShip> > temp_ships;

        // Set temp collections
        switch(this->current_player) {
            case 1:
                temp_ships = this->player1_ships;
                break;
            case 2:
                temp_ships = this->player2_ships;
                break;
        }
		for(int i = 0; i < temp_ships.size(); i++){
			for(int j = 0; j < temp_ships[i]->GetLocation().size(); j++){
				if(temp_ships[i]->GetLocation()[j]->Equals(a)){
					return true;
				}
			}
		}
		return false;
	}

	/**
	 * This method stops the game and allows the next user to win
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The current user loses and the game stops)
	 */    
    void AMGBattleshipBoard::Forfeit(){
        switch(this->current_player){
            case 1:
                this->player1_ships_left = 0;
                break;
            case 2:
                this->player2_ships_left = 0;
                break;
        }
        
    }
    
    /**
     * This method sets the value of the current player
     * @param a current player
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
	void AMGBattleshipBoard::SetCurrentPlayer(int a){
		if(a == 1 || a == 2){
			this->current_player = a;
		}
	}

    /**
     * This method gets the value of ships left for player 1
     * @return Ships left
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
	int AMGBattleshipBoard::GetPlayer1ShipCount() {
		return this->player1_ships_left;
	}

    /**
     * This method gets the value of ships left for player 2
     * @return Ships left
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is returned)
     */
    int AMGBattleshipBoard::GetPlayer2ShipCount() {
		return this->player2_ships_left;
	}

    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
	AMGBattleshipBoard::AMGBattleshipBoard() {
		this->board_width = 5;
		this->board_height = 5;
		this->ship_count = 3;
		this->current_player = 1;
        this->player1_ships_left = this->ship_count;
        this->player2_ships_left = this->ship_count;
        this->is_shot = false;
	}

    /**
     * This is the common constructor.
	 * @param a Board height
	 * @param b Board width
	 * @param c Ship count
     * @postcondition (A new instance of the object has been created.)
     */
	AMGBattleshipBoard::AMGBattleshipBoard(int a, int b, int c) {
		if(c < a && c < b){
			this->board_width = a;
			this->board_height = b;
			this->ship_count = c;
            this->player1_ships_left = this->ship_count;
            this->player2_ships_left = this->ship_count;
            this->is_shot = false;
		}
        else {
            cout << "Ship count cannot be larger than the board size..." << endl;
        }
        this->current_player = 1;
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
		}
		else {
			cout << "Ship count cannot be larger than the board size..." << endl;
		}
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
	void AMGBattleshipBoard::PrintBoard() {
        vector<shared_ptr<AMGLocation> > temp_shots;
        vector<shared_ptr<AMGLocation> > temp_shots2;
        vector<shared_ptr<AMGShip> > temp_ships;
        int temp_ships_left = 0;
		int temp_shots_count = 0;
        
        // Set temp collections
        switch(this->current_player) {
            case 1:
                temp_shots = this->player2_shots;
                temp_shots2 = this->player1_shots;
                temp_ships = this->player1_ships;
                temp_ships_left = this->player1_ships_left;
				temp_shots_count = this->player1_shots.size();
                break;
            case 2:
                temp_shots = this->player1_shots;
                temp_shots2 = this->player1_shots;
                temp_ships = this->player2_ships;
                temp_ships_left = this->player2_ships_left;
				temp_shots_count = this->player2_shots.size();
                break;
        }
        
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
				if(AlreadyShot(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_shots) && !IsLocationHit(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_ships)){
					cout << IS_SHOT_GRAPHIC;
				}
				else if(IsLocationHit(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_ships) && AlreadyShot(shared_ptr<AMGLocation>(new AMGLocation(j,i)), temp_shots)){
					cout << IS_HIT_GRAPHIC;
				}
				else {
					cout << IS_WATER_GRAPHIC;
				}
			
				// Let the current player know if they have a ship at the location
				if(this->ShipAtLocation(shared_ptr<AMGLocation>(new AMGLocation(j,i)))){
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

		cout << "Player " << (current_player == 1 ? "2" : "1") << " 's shots:" << endl;
		for(int i = 0; i < temp_shots.size(); i++){
			cout << temp_shots[i]->ToString() << endl;
	 	}
        
        cout << endl << endl;
        
        cout << "Player " << (current_player == 1 ? "1" : "2") << " 's shots:" << endl;
        for(int i = 0; i < temp_shots2.size(); i++){
            cout << temp_shots2[i]->ToString() << endl;
        }
	}
}
