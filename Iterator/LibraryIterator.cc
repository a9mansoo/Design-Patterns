#include "Library.h"
#include "LibraryIterator.h"

    // Constructor for the LibraryIterator
    LibraryIterator::LibraryIterator( std::map<std::string,DigitalMedia *>::iterator it ):it{it}{}
    
	// Accesses the current Library object
    DigitalMedia * LibraryIterator::operator*(){
		return it->second;
	}
	
	// Adds Library object to Iterator
    LibraryIterator LibraryIterator::operator++(){
		++it;
		return *this;
	}
	
	
	// Checks if the iterators are the same
    bool LibraryIterator::operator==(const LibraryIterator &other) const{
		return it == other.it;
	}
	
	// Checks if the iterators are different
    bool LibraryIterator::operator!=(const LibraryIterator &other) const{
		return !(*this == other);
	}



