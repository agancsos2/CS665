#ifndef __AMGVENDING_H_INCLUDED__  
#define __AMGVENDING_H_INCLUDED__ 

#include <iostream>
#include <vector>
#include <memory>
#include "../amgcommon/amgcommon_all.h"
#include "../amgpetagencycommon/amgpetagencycommon_all.h"
#include "../amgpetagencybuilder/amgpersonbuilder/amgpersonbuilder_all.h"
#include "../amgpetagencybuilder/amganimalbuilder/amganimalbuilder_all.h"
#include "amgpetagency_all.h"
using namespace std;
using namespace amgcommon;
using namespace amgpetagencycommon;
using namespace amgpersonbuilder;
using namespace amganimalbuilder;

namespace amgpetagency {
    /**
     * This class acts as a "session" or wrapping class.
     * @author  (Abel Gancsos)
     * @version (v. 1.0.0)
     */
    class AMGPetAgency {
    	private:
			bool batchable;
            void RunInteractive();
            void RunBatchMode();
			vector<shared_ptr<AMGPerson> > people;
			vector<shared_ptr<AMGAnimal> > available_pets;
			vector<shared_ptr<AMGAnimal> > adopted_pets;
			vector<shared_ptr<AMGBreed> > available_breeds;
            void PrintMenu();
            void RunOperation();
            string input_buffer;
			string input_value;
			string input_value2;
			void InitializeData();
			void ListPeople();
			void ListAvailablePets();
			void ListAdoptedPets();
			void PromptAdoptAnimal();
			void PromptAddPerson();
			void PromptAddAnimal();
			void PromptAddDog();
			void PromptGiveBackAnimal();
			const string animal_types[10] = {"Dog"};
    	public:
        	AMGPetAgency();
        	~AMGPetAgency();
			void SetBatchable(bool a);
			void SetValue(string a);
			bool GetBatchable();
			void Run();
			void SetMode(string a);
    };
}

#endif
