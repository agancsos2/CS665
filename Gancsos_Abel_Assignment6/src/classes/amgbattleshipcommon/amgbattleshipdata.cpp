#include "amgbattleshipdata.h"

namespace amgbattleshipcommon {

    
    /**
     * This method checks if a shot has already been shot
     * @param a Shot location
     * @param b List of shots
     * @precondition  (An instance of the object must exist)
     * @postcondition (The result of the lookup)
     */    
    bool AMGBattleshipData::NotAleradyShot(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGLocation> > b) {
        for(int i = 0; i < b.size(); i++){
            if(a->Equals(b[i])){
                return true;
            }
        }
        return false;
    }
    
    /**
     * This method adds a new shot to the current player's collection
     * @param a Shot location
     * @precondition  (An instance of the object must exist)
     * @postcondition (The shot was added and the result is returned)
     */
    void AMGBattleshipData:: AddShot(shared_ptr<AMGLocation> a) {
        this->player_shots.push_back(a);
    }
    
    /**
     * This method adds a new shot to the opponent player's collection and checks if a ship was hit
     * @param a Shot location
     * @param b Opponent data
     * @precondition  (An instance of the object must exist)
     * @postcondition (The shot was added and the result is returned)
     */
    void AMGBattleshipData::AddShot(shared_ptr<AMGLocation> a, shared_ptr<AMGBattleshipData> b){
        if(!NotAleradyShot(a, b->GetPlayerShots())){
            b->AddShot(a);
            this->is_shot = ShipAtLocation(a, this->player_ships);
            if(this->is_shot) {
                this->player_ships_left--;
            }
        }
        else{
            cout << "Shot was already taken at location..." << endl;
        }
    }
    
    /**
     * This method checks if the last shot was a hit
     * @return True if it was a hit, false if not
     * @precondition  (An instance of the object must exist)
     * @postcondition (The result is returned)
     */
    bool AMGBattleshipData::WasShot() {
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
    bool AMGBattleshipData::ShipAtLocation(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b){
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
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */
    int AMGBattleshipData::GetShipCount(){
        return this->player_ships.size();
    }
    
    /**
     * This method adds a ship to the given user
     * @param a Location to lookup
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The ship is added to the player)
     */
    void AMGBattleshipData::AddShip(shared_ptr<AMGLocation> a) {
        if(! this->ShipAtLocation(a, player_ships)){
            this->player_ships.push_back(shared_ptr<AMGShip>(new AMGShip(a->GetXCoordinates(), a->GetYCoordinates())));
        }
    }
    
    /**
     * This method retrieves the player's shots
     * @return Shots
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The player's shots were returned)
     */
    vector<shared_ptr<AMGLocation> > AMGBattleshipData::GetPlayerShots(){
        return this->player_shots;
    }
    
    /**
     * This method retrieves the player's ships
     * @return Ships
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The player's ships were returned)
     */
    vector<shared_ptr<AMGShip> > AMGBattleshipData::GetPlayerShips(){
        return this->player_ships;
    }
    
    /**
     * This method sets the number of ships to start with
     * @param a Number of ships
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The player's ships count were set)
     */
    void AMGBattleshipData::SetShipCount(int a){
        this->player_ships_left = a;
    }
    
    /**
     * This method retrieves the number of ships left for the player
     * @return Number of ships left
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The number of ships left is returned)
     */
    int AMGBattleshipData::GetShipsLeft(){
        return this->player_ships_left;
    }

	/**
 	 * This method retrieves the player number
	 * @return Player number
	 * @precondition  (The instance of the objects must exist)
     * @postcondition (The player's number was returned)
     */
    int AMGBattleshipData::GetPlayerNumber(){
        return this->player_number;
    }
    
    /**
     * This method sets the player number
     * @param a Player number
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The player's number was set)
     */
    void AMGBattleshipData::SetPlayerNumber(int a){
        this->player_number = a;
    }
    
    /**
     * This method checks if the location was hit
     * @param a Location to lookup
     * @param b Collection to look through
     * @return True if it was hit, false if not
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */
    bool AMGBattleshipData::IsLocationHit(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGShip> > b){
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
     * This method checks if the location was already shot at
     * @param a Location to lookup
     * @param b Collection to look through
     * @return True if it was, false if not
     * @precondition  (The instance of the objects must exist)
     * @postcondition (The result of the lookup is returned)
     */
    bool AMGBattleshipData::AlreadyShot(shared_ptr<AMGLocation> a, vector<shared_ptr<AMGLocation> > b){
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
    bool AMGBattleshipData::ShipAtLocation(shared_ptr<AMGLocation> a){
        vector<shared_ptr<AMGShip> > temp_ships;
        for(int i = 0; i < this->player_ships.size(); i++){
            for(int j = 0; j < this->player_ships[i]->GetLocation().size(); j++){
                if(this->player_ships[i]->GetLocation()[j]->Equals(a)){
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
    void AMGBattleshipData::Forfeit(){
        this->player_ships_left = 0;
    }
    
    /**
     * This is the default constructor.
     * @postcondition (A new instance of the object has been created.)
     */
    AMGBattleshipData::AMGBattleshipData(){
		this->player_number = 0;
        this->is_shot = false;
        this->player_ships_left = 0;
    }
    
    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGBattleshipData::~AMGBattleshipData(){
        
    }
    
    /**
     * This is the common constructor.
     * @param a Player number
     * @postcondition (A new instance of the object has been created.)
     */
    AMGBattleshipData::AMGBattleshipData(int a){
        this->player_number = a;
        this->is_shot = false;
        this->player_ships_left = 0;
    }

}
