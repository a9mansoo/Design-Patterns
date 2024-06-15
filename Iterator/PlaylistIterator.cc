#include "Playlist.h"
#include "PlaylistIterator.h"

// Curr it in the iterators in the pointer to the implementations iterator
    // PlaylistIterator Constructor
    PlaylistIterator::PlaylistIterator(std::vector<DigitalMedia*>::iterator  it): it{it}, timeElapsed{0}{}
    
	int PlaylistIterator::getElapsedTime() const{
		return timeElapsed;
	}

    // Caller "plays" the item by printing its information to std::cout.
    DigitalMedia * PlaylistIterator::operator*(){
		return *it;
	}
     
    // Adds the duration of the item just played to the total time elapsed so far before moving
    // the iterator.
    PlaylistIterator PlaylistIterator::operator++(){
		timeElapsed = timeElapsed;
		++it;
		return *this;
	}

    bool PlaylistIterator::operator==(const PlaylistIterator &other) const{
		return it== other.it;
	}
    bool PlaylistIterator::operator!=(const PlaylistIterator &other) const{
		return !(*this == other);
	}



