#include <iostream>
#include "classes/amgcommon/amgcommon_all.h"
using namespace std;
using namespace amgcommon;

void HelpMenu() {
    cout << AMGString("").PadRight(80, "=") << endl;
    cout << AMGString("").PadRight(80, "=") << endl;
}

int main(int argc, char **argv) {
	HelpMenu();
    return 0;
}
