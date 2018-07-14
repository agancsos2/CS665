#ifndef __AMGPERSON_H_INCLUDED__
#define __AMGPERSON_H_INCLUDED__

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

namespace amgdispatchcommon {

	/**
	 * This class represents a person object
	 */
	class AMGPerson {
		protected:
			string ssn;
			string first_name;
			string last_name;
			int age;
			bool birthday;
		public:
			AMGPerson();
			~AMGPerson();
			AMGPerson(string first, string last, int age);
			void SetFirst(string first);
			void SetLast(string last);
			void SetAge(int age);
			string GetFirst();
			string GetLast();
			int GetAge();
			bool HasBirthday();
			void SetBirthday(bool a);	
			virtual string GetType() = 0;
			virtual string ToString() = 0;
    };
}
#endif

