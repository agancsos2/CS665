#include "amgpetagency.h"

namespace amgpetagency {

	/**
	 * This method performs the operations needed to adopt an animal
	 * @precondition  (The instance of the session class must exist)
	 * @postcondition (The animal is adopted if valid)
	 */
	void AMGPetAgency::PromptAdoptAnimal(){
		if(available_pets.size() > 0 && people.size() > 0){
        	if(!batchable){
				// List available pets
            	cout << "Are you sure you want to adopt an animal? ";
            	cin >> input_buffer;
            	cout << endl;
            	if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::BOOL)){
                	cout << "Enter an option from the list below:" << endl;
                	for(int i = 0; i < available_pets.size(); i++){
                    	cout << i << ". " << available_pets.at(i)->ToString() << endl;
                	}
                	cout << "Option: ";
                	cin >> input_value;
                	cout << endl;
            	}
        	}
			// If input is valid
        	if(AMGSystem::ValidateInput(input_value, INPUT_TYPES::NUMBER)){
            	if(stoi(input_value) < available_pets.size() && stoi(input_value) >= 0){
					if(!batchable){
						// Prompt for new owner
						cout << "Enter option for new owner: " << endl;
						for(int i = 0; i < people.size(); i++){
							cout << i << ". " << people.at(i)->GetFirstName() << " " << people.at(i)->GetLastName() << endl;
						}
						cout << "Option: ";
						cin >> input_value2;
						cout << endl;
					}
					else{
						// Just use first person if batchable.  Since there is default data in memory, there 
						// should always be at least 1 person.
						input_value2 = "0";
					}
					
					if(AMGSystem::ValidateInput(input_value2, INPUT_TYPES::NUMBER)){
                		if(stoi(input_value2) < people.size() && stoi(input_value2) >= 0){					
					        available_pets.at(stoi(input_value))->Adopt(people.at(stoi(input_value2)), true);
                    		adopted_pets.push_back(available_pets[stoi(input_value)]);
                    		available_pets.erase(available_pets.begin() + stoi(input_value));
						}
					}
            	}
            	else{
                	cout << "Option was out of scope..." << endl;
            	}
        	}
        	else{
            	cout << "Option was not a valid value..." << endl;
        	}
		}
	}

    /**
     * This method performs the operations needed to add a person
     * @precondition  (The instance of the session class must exist)
     * @postcondition (The person is added into memory)
     */
    void AMGPetAgency::PromptAddPerson(){
		if(this->batchable){
			throw invalid_argument("Operation not supported in batch mode...");
		}
	
		string first_name = "";
		string last_name = "";
		cout << "First name: ";
		cin >> input_buffer;
		if(input_buffer != ""){
			first_name = input_buffer;
		}
		cout << "Last name: ";
		cin >> input_buffer;
		if(input_buffer != ""){
			last_name = input_buffer;
		}

		AMGPerson::PersonBuilder *new_builder = new AMGPerson::PersonBuilder(first_name, last_name);
        cout << "Gender? (1-NA, 2-MALE, 3-FEMALE): ";
        cin >> input_buffer;
        if(input_buffer == ""){
            input_buffer = "1";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            switch(stoi(input_buffer)){
                case 1:
                    new_builder = new_builder->WithGender(GENDER::NONE);
                    break;
                case 2:
                    new_builder = new_builder->WithGender(GENDER::MALE);
                    break;
                case 3:
                    new_builder = new_builder->WithGender(GENDER::FEMALE);
                    break;
                default:
                    cout << "Option was not valid..." << endl;
                    break;
            }
        }
        else{
            cout << "Input was in incorrect format...." << endl;
        }

        cout << "Height(in): ";
        cin >> input_buffer;
        if(input_buffer == ""){
            input_buffer = "0";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            new_builder = new_builder->WithHeight(stoi(input_buffer));
        }
        cout << "Weight(lb): ";
        cin >> input_buffer;
        if(input_buffer == ""){
            input_buffer = "0";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            new_builder = new_builder->WithWeight(stoi(input_buffer));
        }

		cout << "Waist Size: ";
        cin >> input_buffer;
        if(input_buffer == ""){
            input_buffer = "0";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            new_builder = new_builder->WithWaistSize(stoi(input_buffer));
        }

		cout << "Age: ";
        cin >> input_buffer;
        if(input_buffer == ""){
            input_buffer = "0";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            new_builder = new_builder->WithAge(stoi(input_buffer));
        }

        cout << "Nationality: " << endl;
        for(int i = 0; i < (sizeof(AMGCommonEnums::ALL_NATIONALITIES) / sizeof(NATIONALITY)); i++){
            cout << i << ". " << AMGCommonEnums::GetNationalityName(AMGCommonEnums::ALL_NATIONALITIES[i]) << endl;
        }
        cout << "Option: ";
        cin >> input_buffer;
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            if(stoi(input_buffer) > -1 && stoi(input_buffer) < (sizeof(AMGCommonEnums::ALL_NATIONALITIES) / sizeof(NATIONALITY))){
                new_builder = new_builder->WithNationality(AMGCommonEnums::ALL_NATIONALITIES[stoi(input_buffer)]);
            }
        }

		cout << "Race: " << endl;
		for(int i = 0; i < (sizeof(AMGCommonEnums::ALL_RACES) / sizeof(RACE)); i++){
			cout << i << ". " << AMGCommonEnums::GetRaceName(AMGCommonEnums::ALL_RACES[i]) << endl;
		}
		cout << "Option: ";
		cin >> input_buffer;
		if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
			if(stoi(input_buffer) > -1 && stoi(input_buffer) < (sizeof(AMGCommonEnums::ALL_RACES) / sizeof(RACE))){
				new_builder = new_builder->WithRace(AMGCommonEnums::ALL_RACES[stoi(input_buffer)]);
			}	
        }

        cout << "Hair Color: " << endl;
        for(int i = 0; i < (sizeof(AMGCommonEnums::ALL_HAIR_COLORS) / sizeof(HAIR_COLOR)); i++){
            cout << i << ". " << AMGCommonEnums::GetHairColorName(AMGCommonEnums::ALL_HAIR_COLORS[i]) << endl;
        }
        cout << "Option: ";
        cin >> input_buffer;
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            if(stoi(input_buffer) > -1 && stoi(input_buffer) < (sizeof(AMGCommonEnums::ALL_HAIR_COLORS) / sizeof(HAIR_COLOR))){
                new_builder = new_builder->WithHairColor(AMGCommonEnums::ALL_HAIR_COLORS[stoi(input_buffer)]);
            }
        }

        cout << "Eye Colors: " << endl;
        for(int i = 0; i < (sizeof(AMGCommonEnums::ALL_EYE_COLORS) / sizeof(EYE_COLOR)); i++){
            cout << i << ". " << AMGCommonEnums::GetEyeColorName(AMGCommonEnums::ALL_EYE_COLORS[i]) << endl;
        }
        cout << "Option: ";
        cin >> input_buffer;
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            if(stoi(input_buffer) > -1 && stoi(input_buffer) < (sizeof(AMGCommonEnums::ALL_EYE_COLORS) / sizeof(EYE_COLOR))){
                new_builder = new_builder->WithEyeColor(AMGCommonEnums::ALL_EYE_COLORS[stoi(input_buffer)]);
            }
        }

        this->people.push_back(new_builder->Build());
        cout << "New future adopter added!" << endl;
	}

	/**
	 * This method builds a dog based on user input
	 * @precondition  (An instance of the object must exist)
	 * @postcondition (A new dog was built)
	 */
	void AMGPetAgency::PromptAddDog() {
		input_buffer = "";
		cout << "What's there name?: ";
		cin >> input_buffer;
		AMGDog::DogBuilder *new_builder = new AMGDog::DogBuilder(input_buffer);
		input_buffer = "";
		cout << "Gender? (1-NA, 2-MALE, 3-FEMALE): ";
		cin >> input_buffer;
		if(input_buffer == ""){
			input_buffer = "1";
		}
		if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
			switch(stoi(input_buffer)){
				case 1:
					new_builder = new_builder->WithGender(GENDER::NONE);
					break;
				case 2:
                    new_builder = new_builder->WithGender(GENDER::MALE);
					break;
				case 3:
                    new_builder = new_builder->WithGender(GENDER::FEMALE);
					break;
				default:
					cout << "Option was not valid..." << endl;
					break;
			}
		}
		else{
			cout << "Input was in incorrect format...." << endl;
		}

		cout << "Height(in): ";
		cin >> input_buffer;
		if(input_buffer == ""){
            input_buffer = "0";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
			new_builder = new_builder->WithHeight(stoi(input_buffer));
		}
		cout << "Weight(lb): ";
        cin >> input_buffer;
        if(input_buffer == ""){
            input_buffer = "0";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
            new_builder = new_builder->WithWeight(stoi(input_buffer));
        }
		cout << "Breed?:" << endl;
		for(int i = 0; i < this->available_breeds.size(); i++){
			cout << i << ". " << this->available_breeds[i]->ToString() << endl;
		}
		cout << "Option: ";
		cin >> input_buffer;
		if(input_buffer == ""){
            input_buffer = "0";
        }
        if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
			if(stoi(input_buffer) > -1 && stoi(input_buffer) < this->available_breeds.size()){
				new_builder = new_builder->WithBreed(this->available_breeds[stoi(input_buffer)]);
			}
		}

		this->available_pets.push_back(new_builder->Build());
		cout << "New animal was added and needs a home!" << endl;
	}

    /**
     * This method performs the operations needed to add an animal
     * @precondition  (The instance of the session class must exist)
     * @postcondition (The animal is added into the available pets list)
     */
    void AMGPetAgency::PromptAddAnimal(){
		if(this->batchable){
			throw invalid_argument("Operation not supported in batch mode...");
		}

		input_buffer = "";
		cout << "Please select an animal type to add: " << endl;
		for(int i = 0; i < (sizeof(this->animal_types)/sizeof(string)); i++){
			if(this->animal_types[i] != ""){
				cout << i << ". (" << this->animal_types[i] << ")" << endl;
			}
		}
		cout << "Option: ";
		cin >> input_buffer;

		// If the response was not blank
		if(input_buffer != ""){
			// If the input was a number
			if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)){
				// If the response was within range
				if(stoi(input_buffer) > -1 && stoi(input_buffer) < (sizeof(this->animal_types)/sizeof(string))){
					// Create the appropriate animal through builders
					switch(stoi(input_buffer)){
						case 0:
							PromptAddDog();
							break;
						defaut:
							cout << "Builder is not implemented...." << endl;
							break;
					}	
				}
			}
			else {
				cout << "Option was not in valid format..." << endl;
			}
		}
		else{
			cout << "No option was selected..." << endl;
		}
	}

    /**
     * This method performs the operations needed to return an animal
     * @precondition  (The instance of the session class must exist)
     * @postcondition (The animal is returned if valid)
     */
    void AMGPetAgency::PromptGiveBackAnimal(){
		if(adopted_pets.size() > 0){
			if(!batchable){
				// Prompt for animal from the list
				cout << "Are you sure you want to give back an animal? ";
				cin >> input_buffer;
				cout << endl;
				if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::BOOL)){
					cout << "Enter an option from the list below:" << endl;
					for(int i = 0; i < adopted_pets.size(); i++){
						cout << i << ". " << adopted_pets.at(i)->ToString() << endl;
					}
					cout << "Option: ";
					cin >> input_value;
					cout << endl;
				}
			}
			// If input is valid
			if(AMGSystem::ValidateInput(input_value, INPUT_TYPES::NUMBER)){
				if(stoi(input_value) < adopted_pets.size() && stoi(input_value) >= 0){
					adopted_pets.at(stoi(input_value))->Adopt(nullptr, false);
					available_pets.push_back(adopted_pets[stoi(input_value)]);
					adopted_pets.erase(adopted_pets.begin() + stoi(input_value));
				}
				else{
					cout << "Option was out of scope..." << endl;
				}
			}
			else{
				cout << "Option was not a valid value..." << endl;
			}
		}
	}

    /**
     * This is the default constructor
     * @postcondition (A new AMGString object has been created.)
     */
    AMGPetAgency::AMGPetAgency(){
  		batchable = false;      
		input_buffer = "";
    }

	/**
	 * This method sets the batchable flag
	 * @param a Value to set for the flag
	 * @precondition  (An instance of the object must exist)
	 * @postcondition (The flag is set)
	 */
	void AMGPetAgency::SetMode(string a){
		input_buffer = a;
	}

    /**
     * This method sets the value property
     * @param a Value to set for the property
     * @precondition  (An instance of the object must exist)
     * @postcondition (The property is set)
     */
    void AMGPetAgency::SetValue(string a){
        input_value = a;
    }

	/**
	 * This adds the default data into memory
	 * @precondition  (The instance of the session class must exist)
	 * @postcondition (The data has been added into memory)
	 */
	void AMGPetAgency::InitializeData(){

		// Add breeds
		available_breeds.push_back(shared_ptr<AMGBreed>(new AMGBreed("Labrador")));
		available_breeds.push_back(shared_ptr<AMGBreed>(new AMGBreed("Beagle")));

		// Add people
		people.push_back((new AMGPerson::PersonBuilder("Robert", "Robinson"))->Build());

		// Add animals
		available_pets.push_back((new AMGDog::DogBuilder("Rosco"))->WithGender(GENDER::MALE)->Build());
		adopted_pets.push_back((new AMGDog::DogBuilder("Spot"))->Build());

		// Adopt an animal
		adopted_pets.at(0)->Adopt(people.at(0), false); 
	}

	/**
	 * This method lists the people in memory
	 * @precondition  (The instance of the session class must exist)
	 * @postcondition (The list of people have been displayed)
	 */
	void AMGPetAgency::ListPeople() {
		for(int i = 0; i < people.size(); i++) {
			cout << i << ". " << people.at(i)->ToString() << endl;
		}
	}

    /**
     * This method lists the pets in memory
     * @precondition  (The instance of the session class must exist)
     * @postcondition (The list of available pets have been displayed)
     */
    void AMGPetAgency::ListAvailablePets() {
        for(int i = 0; i < available_pets.size(); i++) {
            cout << i << ". " << available_pets.at(i)->ToString() << endl;
        }
    }

    /**
     * This method lists the pets in memory
     * @precondition  (The instance of the session class must exist)
     * @postcondition (The list of available pets have been displayed)
     */
    void AMGPetAgency::ListAdoptedPets() {
        for(int i = 0; i < adopted_pets.size(); i++) {
            cout << i << ". " << adopted_pets.at(i)->ToString() << endl;
        }
    }
    
    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGPetAgency::~AMGPetAgency() {
        
    }

    /**
     * This method prints the options in an interactive session
     * @precondition  (The instance of the object exists)
     * @postcondition (The drink order is built)
     */
    void AMGPetAgency::PrintMenu(){
        input_buffer = "";
        cout << "Welcome to AMGPetAgency" << endl;
		cout << "Select an operation to perform: " << endl;
		cout << "\t0. Exit" << endl;
        cout << "\t1. List People" << endl;
        cout << "\t2. List Available Pets" << endl;
        cout << "\t3. List Adopted Pets" << endl;
        cout << "\t4. Adopt Pet" << endl;
        cout << "\t5. Return Pet" << endl;
		cout << "\t6. Add Person" << endl;
		cout << "\t7. Add Animal" << endl;
		cout << "Option: ";
		cin >> input_buffer;
		cout << endl;
    }

    /**
     * This method performs the actual operation (ie. dispensing the drink)
     * @precondition  (The instance of the object exists)
     * @postcondition (The drink is dispensed)
     */
    void AMGPetAgency::RunOperation(){
		if(AMGSystem::ValidateInput(input_buffer, INPUT_TYPES::NUMBER)) {
			switch(stoi(input_buffer)){
				case 0:
					AMGSystem::ExitProgram();
					break;
				case 1:
					ListPeople();
					break;
				case 2:
					ListAvailablePets();
					break;
				case 3:
					ListAdoptedPets();
					break;
				case 4:
					PromptAdoptAnimal();
					break;
				case 5:
					PromptGiveBackAnimal();
					break;
				case 6:
					PromptAddPerson();
					break;
				case 7:
					PromptAddAnimal();
					break;
				default:
					cout << "Operation is not supported..." << endl;
					break;
			}
		}
		else{
			cout << "Input is not in proper format..." << endl;
		}
	}

    /**
     * This method performs session operations with user input
     * @precondition  (The instance of the object exists)
     * @postcondition (The patron is prompted)
     */
    void AMGPetAgency::RunInteractive(){
        while(0 == 0){
            PrintMenu();
            RunOperation();
        }
    }

    /**
     * This method runs the session in a batch mode
     * @precondition  (The instance of the object exists)
     * @postcondition (The operations are performed without user input)
     */
    void AMGPetAgency::RunBatchMode(){
        RunOperation();
    }

    /**
     * This method sets the mode to batchable
     * @param a Value to set for the flag
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is set)
     */
    void AMGPetAgency::SetBatchable(bool a){
        batchable = a;
    }

    /**
     * This method retrieves the batchable flag
     * @return        (Value of the flag)
     * @precondition  (The instance of the object exists)
     * @postcondition (The value of the flag is returned)
     */
    bool AMGPetAgency::GetBatchable(){
        return batchable;
    }

    /**
     * This method is the main entry to the controller and prepares the session
     * @precondition  (The instance of the object exists)
     * @postcondition (The patron is prompted or the operations are ran in batch mode)
     */
    void AMGPetAgency::Run(){
		InitializeData();
        if(batchable){
            RunBatchMode();
        }
        else{
            RunInteractive();
        }
    }
}
