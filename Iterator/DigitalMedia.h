#ifndef _DIGITAL_MEDIA
#define _DIGITAL_MEDIA

#include <string>
#include <iostream>
#include <stdexcept> // std::length_error, std::invalid_argument, std::runtime_error

class DigitalMedia {
private:
	std::string key; // key of the Digital Media
	std::string title; // title of the Digital Media
	int duration; // Duration of Digital Media in seconds
	const std::string& checkKey(const std::string&); // checks the key length > 1 and throws exception otherwise
	const std::string& checkTitle(const std::string&); // checks title length > 1 and throws exception otherwise
	const int checkDuration(const int); // checks duration > 1 and throws exception otherwise
protected:
	//DigitalMedia &operator=(DigitalMedia &); Digital Media copy assignment operator
	void setKey(std::string key);
	void setTitle(std::string title);

public:
    // Sets key, title and duration information.
    // Raises: std::length_error if key.length() < 1 or title.length() < 1
    //         std::invalid_argument if duration < 1 (checks are made in order listed)
    DigitalMedia( const std::string & key, const std::string & title, int duration );
    virtual ~DigitalMedia();

    // Concrete subclasses use this to invoke their output operator so that Library
    // container can successfully print its contents using the iterator.
    virtual void print( std::ostream & out ) = 0;

    const std::string & getKey() const;
    const std::string & getTitle() const;
    int getDuration() const;
};

#endif


