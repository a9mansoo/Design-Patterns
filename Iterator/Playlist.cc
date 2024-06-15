#include "Playlist.h"
#include <string>
#include <sstream>

	// Constructor for Playlist
    Playlist::Playlist( ): totalSeconds{0},secondsPlayedSoFar{0}{}
	
	// Destructor for the Playlist
    Playlist::~Playlist(){
		for (auto x: media){
			if (x != nullptr) {
				std::cout << "Deleting playlists" << std::endl;
				delete x;
			}
		}
	}

	
	// Resets the secondsPlayedSoFar to 0
    void Playlist::reset(){ // resets the elapsed time back to 0
		secondsPlayedSoFar = 0;
	}
	
	// Searches through current playlist of DigitalMedia returns true if the key is present
	// false otherwise
	bool Playlist::searchPlaylist( DigitalMedia * m){
		int size = media.size();
		for ( int i = 0; i < size; ++i ){
			if ( media[i] == m ){
				return true;
			}
		}
		return false;
	}
	
	// Adds the DigitalMedia m to the Playlist vector
    void Playlist::add( DigitalMedia * m ){
		// Get the key of the DigitalMedia object
		bool present = this->searchPlaylist( m );
		// If it isn't present, add it to the playlist
		if ( !present ){
			media.push_back(m);
		}
	}
	
    void Playlist::remove( DigitalMedia * m ){
		// If the object is in our playlist
		if ( this->searchPlaylist( m ) ){
			// Get size of our vector
			int size = media.size();
			int index = 0;
			// Look for the position of the object
			for ( int i = 0; i < size; ++i ){
				if ( media[i] == m ){
					index = i;
					break;
				}
			}
			// Remove the Digital Media object from playlist
			media.erase(media.begin()+index);
		}
	}
	
	// Sets the PlaylistIterator object pointer to the first DigitalMedia
    PlaylistIterator Playlist::begin(){
		return PlaylistIterator{media.begin()};
	}
    PlaylistIterator Playlist::end(){
		return PlaylistIterator{media.end()};
	}
	
	// Getter for the total seconds of the playlist
    int Playlist::getTotalSeconds() const{
		return totalSeconds;
	}
	
	std::ostream & operator<<( std::ostream & out, Playlist & p ){
		int i = 1;
		std::string temp = "";
		std::string zero = "00";
		for ( auto& it:p.media ){
			std::stringstream ss;
			out << zero;
			ss << i;
			ss >> temp;
			out << temp;
			out<< "  ";
			out << it;
			i += 1;
		}
		std::stringstream ss;
		 i = p.getTotalSeconds();
		ss << i;
		ss >> temp;
		out << "Total: "<< temp << " seconds" << std::endl;
		return out;
	}

