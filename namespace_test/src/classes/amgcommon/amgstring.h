#ifndef __AMGSTRING_H_INCLUDED
#define __AMGSTRING_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace amgcommon {
    class AMGString{
        private:
            static string str;
        public:
            AMGString();
            AMGString(string a);
            ~AMGString();
            string PadRight(int len, string pad); 
            string PadLeft(int len, string pad); 
    };
}
#endif
