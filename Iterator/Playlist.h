#ifndef _PLAYLIST_
#define _PLAYLIST_

#include <string>
#include <sstream>
#include "PlaylistIterator.h"

class DigitalMedia; // forward declaration

class Playlist {
    friend std::ostream & operator<<( std::ostream & out, Playlist & p );    
private:
    int totalSeconds; // total seconds of playlist
	int secondsPlayedSoFar; // time elapsed of the playlist in seconds
    // vector of pointers to the DigitalMedia object
    std::vector<DigitalMedia *> media;
	bool searchPlaylist( DigitalMedia * ); // Method to search through current playlist


public:
    Playlist();
    virtual ~Playlist();
    void reset(); // resets the elapsed time back to 0
    void add( DigitalMedia * m );
    void remove( DigitalMedia * m );
    PlaylistIterator begin();
    PlaylistIterator end();
    int getTotalSeconds() const;
};

std::ostream & operator<<( std::ostream & out, Playlist & p );

#endif



