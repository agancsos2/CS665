#include "amgtracer.h"

/**
 * This is the default constructor
 * @precondition  (There is a need to log information)
 * @postcondition (A new AMGTracer object is created)
 */
AMGTracer::AMGTracer(){
	output_file = "";
}

/**
 * This is the common constructor
 * @param a Full path to the output file
 * @precondition  (There is a need to log information)
 * @postcondition (A new AMGTracer object is created)
 */
AMGTracer::AMGTracer(string a){
	output_file = a;
}

/**
 * This is the deconstructor
 * @postcondition (The instance of the object is removed from memory)
 */
AMGTracer::~AMGTracer(){
}

/**
 * This method sets the value for the output file
 * @param a Full path to the output file
 * @precondition  (The AMGTracer object exists)
 * @postcondition (The value for the output file was set)
 */
void AMGTracer::SetOutputFile(string a){
	output_file = a;
}

/**
 * This method logs data to an output file
 * @param a Value to b appended in th file
 * @param print Option to print details to the console
 * @precondition  (An output file must be accessible)
 * @postcondition (The data was appended to the output file)
 */
void AMGTracer::Trace(string a, bool print){
	if(print){
		cout << a << endl;
	}
	try{
		string trace_text = "";
		if(AMGSystem().FileExists(output_file)){
			trace_text = AMGSystem(output_file).ReadFile();
			trace_text += "\n";
		}
		time_t now = time(0);
        trace_text += AMGString(string(ctime(&now))).Strip();
        trace_text += (" " + a);
    	AMGSystem("",output_file).WriteFile(trace_text);
	}
	catch(exception &e){
	}
}
