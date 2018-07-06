#ifndef __AMGTRACER_H_INCLUDED
#define __AMGTRACER_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

namespace amgcommon {
    class AMGTracer {
        private:
            static string output_file;
        public:
            AMGTracer();
            AMGTracer(string a);
            ~AMGTracer();
            void Trace(string a, bool b);
    };
}

#endif