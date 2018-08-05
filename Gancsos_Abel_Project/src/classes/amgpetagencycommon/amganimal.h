#ifndef __AMGANIMAL_H_INCLUDED
#define __AMGANIMAL_H_INCLUDED

#include <iostream>
#include <vector>
#include "amgbreed.h"
#include <memory>
#include "amgcommonenums.h"
#include "amgperson.h"
using namespace std;

namespace amgpetagencycommon {

	/**
	 * This class represents a generic animal
	 */
	class AMGAnimal {
		protected:
			const static int adoption_time_seconds = 0;
			GENDER gender;
			string name;
			float height;
			float weight;
			shared_ptr<AMGPerson> owner;
			shared_ptr<AMGBreed> breed;
		public:
			AMGAnimal();
			virtual ~AMGAnimal() = 0;
			virtual string ToString() = 0;
			virtual string GetType() = 0;
			virtual void Adopt(shared_ptr<AMGPerson> a, bool delay) = 0;
			virtual GENDER GetGender() = 0;
            virtual string GetName() = 0;
            virtual float GetHeight() = 0;
            virtual float GetWeight() = 0;
            virtual shared_ptr<AMGPerson> GetOwner() = 0;
            virtual void SetGender(GENDER a) = 0;
            virtual void SetOwner(shared_ptr<AMGPerson> a) = 0;
            virtual void SetHeight(float a) = 0;
            virtual void SetWeight(float a) = 0;
            virtual void SetBreed(shared_ptr<AMGBreed> a) = 0;
			virtual void SetName(string a) = 0;
	};
}

#endif
