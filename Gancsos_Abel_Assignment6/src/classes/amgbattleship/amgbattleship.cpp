#include "amgbattleship.h"

namespace amgbattleship {

	/**
	 * This method prints the final scores
	 * @precondition  (The instance of the object must exist)
     * @postcondition (The prompt was displayed)
     */
	void AMGBattleship::PrintGameOver() {
		if(this->player1_board->GetData()->GetShipsLeft() > this->player2_board->GetData()->GetShipsLeft()){
            cout << "Player 1 WINS!!!" << endl;
        }
        if(this->player2_board->GetData()->GetShipsLeft() > this->player1_board->GetData()->GetShipsLeft()){
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
        this->player1_board = shared_ptr<AMGBattleshipBoard>(new AMGBattleshipBoard());
        this->player2_board = shared_ptr<AMGBattleshipBoard>(new AMGBattleshipBoard());
        this->player1_board->GetData()->SetPlayerNumber(1);
        this->player2_board->GetData()->SetPlayerNumber(2);
		this->current_player = 0;
		this->input_buffer = "";
	}

	/**
	 * This method prompts the current user for a location on the board to fire at
     * @param a Opponents data strictly for checking
	 * @precondition  (The instance of the object must exist)
	 * @postcondition (The prompt was displayed)
	 */
	void AMGBattleship::PromptUser(shared_ptr<AMGBattleshipData> a){

		this->input_buffer = "";
		vector<string> pairs = AMGString(this->input_buffer).Split(",");
		while(this->input_buffer == ""){
			cout << "PLAYER" << this->current_player << " - Please select X,Y coordinates to target: ";
			cin >> this->input_buffer;

			// Forefeit
			if(this->input_buffer == "#"){
                switch(this->current_player) {
                    case 1:
                        this->player1_board->GetData()->Forfeit();
                        break;
                    case 2:
                        this->player2_board->GetData()->Forfeit();
                        break;
                }
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

				if(stoi(pairs[0]) > this->player1_board->GetBoardWidth() - 1 || stoi(pairs[1]) > this->player1_board->GetBoardHeight() - 1 ||
					stoi(pairs[0]) < 0 || stoi(pairs[1]) < 0){
					cout << "Coordinates are not within range of the map..." << endl;
					this->input_buffer = "";
					continue;
				}
                
                shared_ptr<AMGLocation> new_location(new AMGLocation(stoi(pairs[0]), stoi(pairs[1])));
                switch(this->current_player){
                    case 1:
                        this->player2_board->SubmitAttack(new_location, player1_board);
                        break;
                    case 2:
                        this->player1_board->SubmitAttack(new_location, player2_board);
                        break;
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
        this->player1_board->SetBoardHeight(a);
        this->player2_board->SetBoardHeight(a);
	}

    /**
     * This method sets the value of the board width
     * @param a Board width
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
    void AMGBattleship::SetBoardWidth(int a) {
        this->player1_board->SetBoardWidth(a);
        this->player2_board->SetBoardWidth(a);
	}

    /**
     * This method sets the value of the ship count
     * @param a Number of ships on the board
     * @precondition  (The instance of the object must exist)
     * @postcondition (The value is updated)
     */
    void AMGBattleship::SetShipCount(int a) {
        this->player1_board->SetShipCount(a);
        this->player2_board->SetShipCount(a);
	}

    /**
     * This method instantiates the game board and starts the interactive game play
     * @precondition  (The instance of the object must exist)
     * @postcondition (The game board has been initiated)
     */
    void AMGBattleship::Run() {
        this->current_player = 0;
        shared_ptr<AMGBattleshipData> temp_data;
	
		// While both players have ships on the board	
		while(this->player1_board->GetData()->GetShipsLeft() > 0 && this->player2_board->GetData()->GetShipsLeft() > 0){
			// Set the next player
			switch(this->current_player) {
				case 0:
					this->current_player = 1;
                    temp_data = this->player1_board->GetData();
                    this->player1_board->PrintHeader(this->player2_board->GetData());
                    this->player1_board->PrintBoard(this->player2_board->GetData());
					break;
				case 1:
					this->current_player = 2;
                    temp_data = this->player2_board->GetData();
                    this->player2_board->PrintHeader(this->player1_board->GetData());
                    this->player2_board->PrintBoard(this->player1_board->GetData());
					break;
				case 2:
					this->current_player = 1;
                    temp_data = this->player1_board->GetData();
                    this->player1_board->PrintHeader(this->player2_board->GetData());
                    this->player1_board->PrintBoard(this->player2_board->GetData());
					break;
			}
            this->PromptUser(temp_data);
			AMGSystem::Sleep(sleep_seconds);
			AMGSystem::Clear();
        }

		PrintGameOver();
	}
}
