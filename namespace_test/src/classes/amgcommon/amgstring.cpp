#include "amgstring.h"
using namespace amgcommon;

AMGString::AMGString() {

}

AMGString::~AMGString() {
}

AMGString::AMGString(string a) {

}

string AMGString::PadRight(int len, string pad) {
    if(str.length > len) {
        return str.substr(len - str.length - 1, len);
    }
    else {
        string m_final = "";
        for(int i = str.length; i < len; i++) {
            m_final += pad;
        }
        return (str + m_final);
    }
    return "";
}

string AMGString::PadLeft(int len, string pad) {
    if(str.length > len) {
        return str.substr(0, len);
    }
    else {
        string m_final = "";
        for(int i = str.length; i < len; i++) {
            m_final += pad;
        }
        return (str + m_final);
    }
    return "";
}

