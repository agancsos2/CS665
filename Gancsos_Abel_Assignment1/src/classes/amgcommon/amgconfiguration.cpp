#include "amgconfiguration.h"

namespace amgcommon {
    /**
     * This is the default constructor
     * @precondition  (There is a need to log information)
     * @postcondition (A new AMGConfiguration object is created)
     */
    AMGConfiguration::AMGConfiguration(){
        input_file = "";
    }

    /**
     * This is the deconstructor
     * @postcondition (The instance of the object is removed from memory)
     */
    AMGConfiguration::~AMGConfiguration(){
    }

    /**
     * This is the common constructor
     * @param a Full path to the input file
     * @precondition  (There is a need to log information)
     * @postcondition (A new AMGConfiguration object is created)
     */
    AMGConfiguration::AMGConfiguration(string a){
        input_file = a;
    }

    /**
     * This method logs data to an output file
     * @param a Name of the key to lookup
     * @precondition  (An input file must be accessible)
     * @postcondition (The configuration setting is read from the input file)
     */
    string AMGConfiguration::LookupKey(string a){
        if(AMGSystem().FileExists(input_file)){
            try{
                string raw_content = AMGSystem(input_file).ReadFile();
                vector<string> pairs = AMGString(raw_content).SplitByLine();
                for(int i = 0; i < pairs.size(); i++){
                    string pair = pairs[i];
                    vector<string> comps = AMGString(pair).Split("=");
                    if(comps.size() >= 2){
                        if(comps[0][0] != '#'){
                            if(comps[0] == a){
                                return AMGString(comps[1]).Strip();
                            }
                        }
                    }
                }
            }
            catch(exception &e){
            }
        }
        return "";
    }

    /**
     * This method sets the value for the output file
     * @param a Full path to the output file
     * @precondition  (The AMGTracer object exists)
     * @postcondition (The value for the output file was set)
     */
    void AMGConfiguration::SetInputFile(string a){
        input_file = a;
    }

    /**
     * This method retrieves the path to the input file
     * @return Full path to the input file
     * @precondition  (An instance of the object must exist)
     * @postcondition (The full path to the input file is returned)
     */
    string AMGConfiguration::GetInputFile(){
        return input_file;
    }
}
