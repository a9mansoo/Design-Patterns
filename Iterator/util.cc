#include "util.h"



// use these for error checking  in input operator
// *** If getline fails to obtain the necessary argument, raise
// *** std::runtime_error initialized with the fiedlType parameter passed in.
void getString( std::istream & in, std::string & s, const char * fieldType ) {
    getline( in, s );
	if ( fieldType == "key" ){
		if ( s.empty() || s.length() < 1 ){
			throw std::runtime_error("key has length < 1");
		}
	}
	else if ( fieldType == "title" ){
		if ( s.empty() || s.length() < 1 ){
			throw std::runtime_error("title has length < 1");
		}
	}
	else if ( fieldType == "series" ){
		if ( s.empty() || s.length() < 1 ){
			throw std::runtime_error("series has length < 1");
		}
	}
	else if ( fieldType == "artist" ){
		if ( s.empty() || s.length() < 1 ){
			throw std::runtime_error("artist has length < 1");
		}
	}
} // getString

void getInteger( std::istream & in, int & i, const char * fieldType ) {
    std::string s;
    getline( in, s );
    if ( in.fail() ){
		if ( fieldType == "series" ){
			throw std::runtime_error ( "failed to read in series" );
		}
		else if ( fieldType == "duration"){
			throw std::runtime_error ( "failed to read in duration" );
		}
		else if ( fieldType == "episode"){
			throw std::runtime_error ( "failed to read in episode" );
		}
	}
    // *** If std::stoi fails, or getline fails to obtain the necessary argument, raise
    // *** std::runtime_error initialized with the fiedlType parameter passed in.
    i = std::stoi(s);
	if ( i < 1 ){
		if ( fieldType == "series" ){
			throw std::runtime_error ( "failed to read in series" );
		}
		else if ( fieldType == "duration"){
			throw std::runtime_error ( "failed to read in duration" );
		}
		else if ( fieldType == "episode"){
			throw std::runtime_error ( "failed to read in episode" );
		}
	}
} // getInteger


