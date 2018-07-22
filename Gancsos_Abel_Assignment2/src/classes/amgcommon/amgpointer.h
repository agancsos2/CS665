#ifndef __AMGPOINTER_H_INCLUDED__
#define __AMGPOINTER_H_INCLUDED__

#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace amgcommon{
	template <class T>
    class AMGPointer {
        private:
            T *item;
        public:
			explicit AMGPointer(T *item = NULL) { this->item = item; }
   			~AMGPointer() { delete item; }
 			T & operator * () {  return *item; }
   			T * operator -> () { return item; }
			T *Get() { return this->item; }
    };
}

#endif
