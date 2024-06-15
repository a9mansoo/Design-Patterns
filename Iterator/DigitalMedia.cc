#include "DigitalMedia.h"
#include <sstream>

    // checks the key length > 1 and throws exception otherwise 
	const std::string& DigitalMedia::checkKey(const std::string & key){
		if ( key.length() < 1 ){
			throw std::length_error("key has length < 1");
		}
		return key;
	}
	
    // checks the title length > 1 and throws exception otherwise
    const std::string& DigitalMedia::checkTitle(const std::string & title){
		if ( title.length() < 1 ){
			throw std::length_error("title has length < 1");
		}
		return title;
	}
	
    // checks duration > 1 and throws exception otherwise
    const int DigitalMedia::checkDuration(const int duration){
		if ( duration < 1 ){
			throw std::invalid_argument("failed to read in duration");
		}
		return duration;
	}
	
    // Sets key, title and duration information.
    // Raises: std::length_error if key.length() < 1 or title.length() < 1
    //         std::invalid_argument if duration < 1 (checks are made in order listed)
    DigitalMedia::DigitalMedia( const std::string & key, const std::string & title, int duration ):key{checkKey(key)},title{checkTitle(title)},duration{checkDuration(duration)}{}
    
	// Digital Media destructor
	DigitalMedia::~DigitalMedia(){}
/*
	// Move assignment operator
	DigitalMedia & DigitalMedia::operator=(DigitalMedia & rhs){
		// Check for self assignment
		if (this == &rhs) return *this;
		// Else swap the elements
		key = std::move(rhs.key);
		title = std::move(rhs.title);
		duration = rhs.duration;
		return *this;
}
*/
    const std::string & DigitalMedia::getKey() const{
		return key;
	}
    const std::string & DigitalMedia::getTitle() const{
		return title;
	}
    int DigitalMedia::getDuration() const{
		return duration;
	}
	
	void DigitalMedia::setKey(std::string key){
		this->key = key;
	}
	
	void DigitalMedia::setTitle(std::string title){
		this->title = title;
	}
	


