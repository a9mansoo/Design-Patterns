#include "Library.h"
#include "DigitalMedia.h"
#include "Song.h"
#include "TV.h"
#include "LibraryIterator.h"

// Use map which is a dictionary to store key and value which is the Digital Media
    Library::Library(){} // Creates empty library.
    Library::~Library(){} // Destroys all items in library.
	
    LibraryIterator Library::begin(){  // Iterator set to beginning of library contents.
		return LibraryIterator{media.begin()};
	}
    LibraryIterator Library::end(){  // Iterator set past end of library contents.
		return LibraryIterator{media.end()};
	}

    // Stores item, indexed by key. If key already exists, raises std::logic_error
    // and specifies as the message that "key KKKK already exists in library".
    void Library::add( DigitalMedia * m ){
		// Get the key of the media being added
		std::string key = m->getKey();
		std::map<std::string,DigitalMedia *>::iterator it = media.find(key);
		// if the object is not there then insert it
		if ( it == media.end() ){
			media.insert(std::pair<std::string,DigitalMedia *>(key,m));
		}
		else{
			throw std::logic_error{"key " + key + "already exists in library" };
		}
	}   

    void Library::remove( std::string key ){  // Remove item if find key value else does nothing.
		std::map<std::string,DigitalMedia *>::iterator it = media.find(key);
		if ( it != media.end() ){
			media.erase(it);
		}
	}
	
    // Returns pointer to item, or nullptr if not there.
    DigitalMedia * Library::find( std::string key ){
		std::map<std::string,DigitalMedia *>::iterator it = media.find(key);
		// Digital Media object is not found and end of the map it returned
		if ( it == media.end() ){
			return nullptr;
		}
		// The object is found, it is a pointer to the iterator containing the result
		else{
			return it->second;
		}
	}


// Returns modified output stream. Stream contains the header "Library:\n" and the library
// contents, ordered by key. Each object is output using the appropriate output operator
// for the underlying object type, one per line and starting with a tab character.
std::ostream & operator<<( std::ostream & out, Library & library ){
	out << "Library:" << std::endl;
	for ( auto& it:library.media ){
		out << '\t';
		it.second->print(out);
		out << std::endl;
	}
	return out;
}

// Returns modified input stream. Contents of library modified with information read in, 
// where the character 't' on a line specifies a TV show is to be read next, while 's'
// indicates that a Song is to be read in next. Reading continues until EOF is reached
// or an exception is raised. Raises std::runtime_error( "invalid media type" ) if doesn't
// get either 's' or 't'.
std::istream & operator>>( std::istream & in, Library & library ){
	char cmd; 
	in >> cmd;
	if ( in.fail() && cmd != 's' && cmd != 't' ){
		throw std::runtime_error( "invalid media type" );
	}
	while (! in.eof() ){ 
			if ( cmd == 's' ){
				// declare a temp song
				Song s{ "S01", "Great beat and you can dance to it", 183, "Too cool", 
                        "I'd give it a 10!", "Eclectic" };
				in >> s;
				if ( library.find(s.getKey()) == nullptr ){
					library.add(&s);
				}
			}
			else{
				TV t{ "TV01", "Somewhere far away, and long ago", 2580, 1, 1, "Amazing New Show" };
				in >> t;
				if ( library.find(t.getKey()) == nullptr ){
					library.add(&t);
				}
			}
			if ( in.fail() ){
				throw std::runtime_error( "invalid media type" );
			}
	}
	return in;
}


