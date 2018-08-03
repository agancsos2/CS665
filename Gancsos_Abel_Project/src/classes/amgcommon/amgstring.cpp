#include "amgstring.h"

namespace amgcommon{
    /**
     * This is the default constructor
     * @postcondition (A new AMGString object has been created.)
     */
    AMGString::AMGString(){
        str = "";
    }

    /**
     * This method converts the value to all lowercase
     * @precondition  (The value must be set)
     * @postcondition (The value is lowercased)
     * @return Lowercase string
     */
    string AMGString::ToLowerCase(){
        string m_result = "";
        for(int i = 0; i < str.length(); i++){
            m_result += tolower(str[i]);
        }
        return m_result;
    }

    /**
     * This method converts the value to all uppercase
     * @precondition  (The value must be set)
     * @postcondition (The value is uppercased)
     * @return Uppercase string
     */
    string AMGString::ToUpperCase(){
        string m_result = "";
        for(int i = 0; i < str.length(); i++){
            m_result += toupper(str[i]);
        }
        return m_result;
    }

    /**
     * This is the common constructor
     * @param str Value to set for the class
     * @precondition  (There is a string that is not empty/null)
     * @postcondition (A new AMGString object has been created from the new string)
     */
    AMGString::AMGString(string st){
        str = st;
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGString::~AMGString(){
    }

    /**
     * This method pads a string
     * @param len Length of the pad
     * @param pad String to use for padding
     * @return Right-padded string
     * @precondition  (The value property of the class is not empty/null)
     * @postcondition (A new right-padded string from the value string)
     */
    string AMGString::PadRight(int len, string pad){
        if(str.length() > len){
            return str.substr(0,len);
        }
        else{
            string m_final = "";
            for(int i = str.length(); i < len; i++){
                m_final += pad;
            }
            return (str + m_final);
        }
    }

    /**
     * This method pads a string
     * @param len Length of the pad
     * @param pad String to use for padding
     * @return Left-padded string
     * @precondition  (The value property of the class is not empty/null)
     * @postcondition (A new left-padded string from the value string)
     */
    string AMGString::PadLeft(int len, string pad){
        if(str.length() > len){
            return str.substr(0,len);
        }
        else{
            string m_final = "";
            for(int i = str.length(); i < len; i++){
                m_final += pad;
            }
            return (m_final + str);
        }
    }

    /**
     * This method splits a string based on a delimeter
     * @param delim String to be used to split the string
     * @return String collection split by a delimeter
     * @precondition  (The instance of the object exists)
     * @postcondition (The string is split into a string collection)
     */
    vector<string> AMGString::Split(string delim){
        vector<string> m_final;
        string buffer = "";
        for(int i = 0; i < str.length(); i++){
            if(buffer == delim || string(1,str[i]) == delim){
                m_final.push_back(buffer);
                buffer = "";
            }
            else{
                buffer += string(1,str[i]);
            }
        }
        if(buffer != ""){
            m_final.push_back(buffer);
        }
        return m_final;
    }

    /**
     * This method splits a string based on line ending
     * @return String collection of the text split by newline
     * @precondition  (The instance of the object exists)
     * @postcondition (The string is split into a string collection)
     */
    vector<string> AMGString::SplitByLine(){
        vector<string> m_final;
        string buffer = "";
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '\0' || str[i] == '\n'){
                m_final.push_back(buffer);
                buffer = "";
            }
            else{
                buffer += string(1,str[i]);
            }
        }
        if(buffer != ""){
            m_final.push_back(buffer);
        }
        return m_final;
    }

    /**
     * This method replaces all occurrences of a string with a different string
     * @param search String to look for
     * @param replace String to replace text with
     * @return A string with the appropriate text
     * @precondition  (The instance of the object exists)
     * @postcondition (All occurrences of the search string are replaced)
     */
    string AMGString::ReplaceAll(const string search, const string replace){
        size_t start = 0;
        while((start = str.find(search, start)) != string::npos){
            str.replace(start,search.length(),replace);
            start += replace.length();
        }
        return str;
    }

    /**
     * This method strips newline characters
     * @return New text with no new line characters
     * @precondition  (The instance of the object exists)
     * @postcondition (Newline characters are replaced from the string)
     */
    string AMGString::Strip(){
        string m_final = str;
        m_final = AMGString(m_final).ReplaceAll("\n","");
        return m_final;
    }

    /**
     * This method checks if the text contains another text
     * @param search Text to look up
     * @return True if exists, false if not
     * @precondition  (The instance of the object exists)
     * @postcondition (The result of the lookup is properly returned)
     */
    bool AMGString::Contains(string search){
        if(AMGString(str).ReplaceAll(search,"") != str){
            return true;
        }
        return false;
    }
}
