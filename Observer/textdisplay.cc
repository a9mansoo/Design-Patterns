#include <cstddef> // defines size_t i.e. an unsigned int
#include <iostream>
#include <vector>
#include "observer.h"
#include "info.h"
#include "cell.h"
#include "textdisplay.h"

    TextDisplay::TextDisplay(size_t n):theDisplay{n,std::vector<char>(n,'_')}, sizedp{n}{}

    void TextDisplay::notify( Subject & whoNotified ){
		Info who = whoNotified.getInfo();
		if ( who.state == State::Alive ){
				theDisplay[who.row][who.col] = 'X';
		}
		else{
			theDisplay[who.row][who.col] = '_';
		}
	}
  
  void TextDisplay::notify(){}
	
    std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
		for ( int row = 0; row < td.theDisplay.size(); ++row ){
			for ( int col = 0; col < td.sizedp; ++col ){
				out << td.theDisplay[row][col];
			}
			out << std::endl;
		}
		return out;
	}
	

