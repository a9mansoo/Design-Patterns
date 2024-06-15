#include "subject.h"
#include "info.h"
#include "cell.h"
#include <vector>

    // Constructor for the cell object
    Cell::Cell(size_t r, size_t c):info{State::Dead,r,c}, neighbours{0}{}
	
    void Cell::setLiving(){
		info.state = State::Alive;
	}
    
    // Resets the neighbour count to 0
	void Cell::reset(){
		neighbours = 0;
	}
	
	Info Cell::getInfo() const{
		return info;
	}
	
	// Current cell, the subject, notifies it's neighbours the observers
	void Cell::notify(){
		if ( info.state == State::Alive ){
			this->notifyObservers();
		}
	}
	
	// Current cell is a subject, gets another subject notifying it, checks state and 
	// notifies its observers
    void Cell::notify( Subject & whoNotified ){
		Info who = whoNotified.getInfo();
		if ( who.state == State::Alive ){
			neighbours += 1;
		}
		else{
			neighbours -= 1;
		}
	}
	
	// Recalculates the current cell's dead or alive status.
	void Cell::recalculate(){
		if ( info.state == State::Alive ){
			if ( neighbours < 2 || neighbours > 3 ){
				info.state = State::Dead;
			}
		}
		else{
			// it's dead
			if ( neighbours == 3 ){
				info.state = State::Alive;
			}
		
	}
	}
	


