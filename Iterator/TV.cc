#include "util.h"
#include "DigitalMedia.h"
#include "TV.h"



    // Checks episode  > 1 throw exception otherwise
    int TV::checkEpisode( const int episode){
		if ( episode < 1 ){
			throw std::invalid_argument("failed to read in episode");
		}
		return episode;
	}

    // Checks season  > 1 throw exception otherwise
    int TV::checkSeason( const int season){
		if ( season < 1 ){
			throw std::invalid_argument("failed to read in season");
		}
		return season;
	}

    // Checks episode  > 1 throw exception otherwise
    const std::string& TV::checkSeries( const std::string & series){
		if ( series.length() < 1 ){
			throw std::invalid_argument("series length < 1");
		}
		return series;
	}
	
    // Sets key, title, duration, episode, season, and series information.
    // Raises: std::length_error if key.length() < 1 or title.length() < 1
    //         std::invalid_argument if duration < 1 
    //         std::length_error if series.length() < 1
    //         std::invalid_argument if episode < 1 or season < 1 
    // (checks are made in order listed)
    TV::TV( const std::string & key, const std::string & title, 
			int duration, int episode, int season, const std::string & series ):DigitalMedia{key,title,duration},
			episode{checkEpisode(episode)},season{checkSeason(season)},series{checkSeries(series)}{}
		 

/*
    TV & TV::operator=(TV & rhs){
		// Check for self assignment
		if ( this == &rhs ) return *this;
		// Else swap the elements
		DigitalMedia::operator=(rhs);
		episode = rhs.episode;
		season = rhs.season;
		series = rhs.series;
		return *this;
	}
*/
    // Destructor for TV
    TV::~TV(){}
	
	
    int TV::getEpisode() const{
		return episode;
	}
    int TV::getSeason() const{
		return season;
	}
    const std::string & TV::getSeries() const{
		return series;
	}
	
	void TV::setEpisode(int episode){
		this->episode = episode;
	}
	
	void TV::setSeason(int season){
		this->season = season;
	}
	
	void TV::setSeries(std::string series){
		this->series = series;
	}
	
	void TV::print( std::ostream & out ){
	out << "(";
	out << this->getKey() << ",";
	std::string temp = this->getSeries();
	temp = "\"" + temp + "\"";
	out << " " << temp << " ";
	int i = 0;
	std::stringstream ss;
	i = this->getSeason();
	ss << i;
	if ( i < 10 ){
		temp = "";
		ss >> temp;
		temp = "0" + temp;
	}
	out << "S" << temp;
	i = this->getEpisode();
	ss.clear();
	ss << i;
	std::string ret = "";
	ss >> ret;
	if ( i < 10 ){
		ret = "0" + ret;
	}
	out << "E" << ret << " ";
	temp = this->getTitle();
	temp = "\"" + temp + "\"";
	out << temp << ", ";
	i = this->getDuration();
	ss.clear();
	ss << i;
	ss >> temp;
	out << temp << ")";
	}
	
// Returns modified output stream. Outputs (key, "series" S<season>E<episode> "title", duration).
// (Explicitly surrounds strings that might have whitespace within with double-quotation marks.
// Season number and episode number have a default width of 2, and must start with '0' if < 10.)
std::ostream & operator<<( std::ostream & out, const TV & t ){
	out << "(";
	out << t.getKey() << ",";
	std::string temp = t.getSeries();
	temp = "\"" + temp + "\"";
	out << " " << temp << " ";
	int i = 0;
	std::stringstream ss;
	i = t.getSeason();
	ss << i;
	if ( i < 10 ){
		temp = "";
		ss >> temp;
		temp = "0" + temp;
	}
	out << "S" << temp;
	i = t.getEpisode();
	ss.clear();
	ss << i;
	std::string ret = "";
	ss >> ret;
	if ( i < 10 ){
		ret = "0" + ret;
	}
	out << "E" << ret << " ";
	temp = t.getTitle();
	temp = "\"" + temp + "\"";
	out << temp << ", ";
	i = t.getDuration();
	ss.clear();
	ss << i;
	ss >> temp;
	out << temp << ")";
	return out;
}

// Returns modified input stream. Contents of t over-written with information read in, where
// format is "key\ntitle\nduration\nseason\nepisode\nseries\n". 
// Raises std::runtime_error if fails to obtain any of the elements, the strings are empty,
// or if duration, season, or episode cannot be successfully converted to an int.
std::istream & operator>>( std::istream & in, TV & t ){
			// Variables to store the string
		std::string key{""};
		std::string title{""};
		int episode = t.getEpisode();
		int season =  t.getSeason();
		std::string series{""};
		int duration = t.getDuration();
		getString( in, key, "key" );
		getString( in, title, "title" );
		getInteger( in, duration, "duration");
		getInteger( in, season, "season" );
		getInteger( in, episode, "episode" );
		getString( in, series, "series" );
		TV temp{key,title,duration,episode,season,series};
		t = temp;
		return in;
	
	}

