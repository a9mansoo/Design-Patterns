#include "util.h"
#include "DigitalMedia.h"
#include "Song.h"


// Check if artist length is valid
    const std::string& Song::checkArtist(const std::string& artist){
		if ( artist.length() < 1 ){
			throw std::length_error("artist has length < 1");
		}
		return artist;
	}
    // Sets key, title, duration, artist, album, and genre information.
    // Raises: std::length_error if key.length() < 1 or title.length() < 1
    //         std::invalid_argument if duration < 1 
    //         std::length_error if artist.length() < 1
    // (checks are made in order listed)
    Song::Song( const std::string & key, const std::string & title, int duration,
         const std::string & artist, const std::string & album, const std::string & genre ):DigitalMedia{key,title,duration},
		 artist{checkArtist(artist)},album{album},genre{genre}{}

	// Destructor for song
    Song::~Song(){}
	/*
    Song & Song::operator=(Song & rhs){
		// Check for self assignment
		if ( this == &rhs ) return *this;
		// Else swap the elements
		DigitalMedia::operator=(rhs);
		artist = rhs.artist;
		album = rhs.album;
		genre = rhs.genre;
		return *this;
	}
*/
	// Getters for the Song object
    const std::string & Song::getArtist() const{
		return artist;
	}
    const std::string & Song::getAlbum() const{
		return album;
	}
    const std::string & Song::getGenre() const{
		return genre;
	}

    void Song::setArtist(std::string artist){
		this->artist = artist;
	}
	
    void Song::setAlbum(std::string album){
		this->album = album;
	}

    void Song::setGenre(std::string genre){
		this->genre = genre;
	}

    // Overriden print method to print according to song format when invoked on Digital Media object.
    void Song::print( std::ostream & out ){
		out << "(";
		out << this->getKey() << ",";
		out << """" << this->getTitle() << """" << ",";
		out << """" << this->getAlbum() << """" << ",";
		out << this->getDuration() << ",";
		out << """" << this->getGenre() << """" << ")";
	}

    // Returns modified output stream. Outputs (key, "title", "album", "artist", duration, "genre").
    // (Explicitly surrounds strings that might have whitespace within with double-quotation marks.)
    std::ostream & operator<<( std::ostream & out, const Song & s ){
	out << "(";
	out << s.getKey() << ",";
	out << """" << s.getTitle() << """" << ",";
	out << """" << s.getAlbum() << """" << ",";
	out << s.getDuration() << ",";
	out << """" << s.getGenre() << """" << ")";
	return out;
	}

    // Returns modified input stream. Contents of s over-written with information read in, where
    // format is "key\ntitle\nduration\nartist\nalbum\ngenre\n". 
    // Raises std::runtime_error if fails to obtain any of the elements, if any of the strings
    // except for genre or album are empty, or if duration cannot be successfully converted to an int.
    std::istream & operator>>( std::istream & in, Song & s ){
		// Variables to store the string
		std::string key{""};
		std::string title{""};
		std::string artist{""};
		std::string album{""};
		std::string genre{""};
		int  duration = s.getDuration();
		getString( in, key, "key" );
		getString( in, title, "title" );
		getInteger( in, duration, "duration");
		getString( in, artist, "artist" );
		std::getline(in,album);
		std::getline(in,genre);
		
		Song temp{key,title,duration,artist,album,genre};
		return in;

}


