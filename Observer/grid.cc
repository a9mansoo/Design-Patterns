#include "grid.h"
#include <iostream>
#include <vector>
#include <cstddef>
#include "cell.h"
#include "textdisplay.h"

    Grid::~Grid(){
		if ( initgrid ){
			delete td;
			td = nullptr;
		}
		for ( auto row: grid){
			row.erase(row.begin() + gridSize);
		}
		grid.clear();
	}


    void Grid::init( size_t n ){  // Sets up an n x n grid.  Clears old grid, if necessary.
		if ( initgrid == false ){
			// Create a 2D vector grid and populate with Cell objects
			gridSize = n;
			td = new TextDisplay{n};
			for ( int row = 0; row < n; ++row ){
				// Declare a vector of Cells
				std::vector<Cell> cells;
				for ( int col = 0; col < n; ++col ){
					// Create a new cell
					Cell curr_cell = Cell{row,col};
					// Attach whatever td is pointing at to the Cell subject
					curr_cell.attach(td);
					// Add the cell
					cells.emplace_back(curr_cell);
				}
				// Add row of cells
				grid.emplace_back(cells);
			}
			// Attach the neighbours of each cell as the observers
		if ( n == 1 ){
			// Only one cell
			grid[0][0].attach(&(grid[0][0]));
		}
		else{
			// Each cell has a neighbour at some dimension
			for ( int row = 0; row < n; ++row ){
				for ( int col = 0; col < n; ++ col ){
					// Evaluate corner case
					if ( (row == 0 && col == 0) ){
						grid[row][col].attach(&(grid[row+1][col+1]));
						grid[row][col].attach(&(grid[row][col+1]));
						grid[row][col].attach(&(grid[row+1][col]));
					}
					else if ( (row == n-1 && col == 0) ){
						grid[row][col].attach(&(grid[row -1][col]));
						grid[row][col].attach(&(grid[row][col+1]));
						grid[row][col].attach(&(grid[row-1][col+1]));
					}
					else if ( (row == n -1 && col == n-1) ){
						grid[row][col].attach(&(grid[row -1][col]));
						grid[row][col].attach(&(grid[row][col-1]));
						grid[row][col].attach(&(grid[row-1][col-1]));
					}
					else if ( (row == 0 && col == n-1) ){
						grid[row][col].attach(&(grid[row+1][col]));
						grid[row][col].attach(&(grid[row][col-1]));
						grid[row][col].attach(&(grid[row+1][col-1]));
					}
					// Evaluate the edge case
					else if ( row == 0  ){
						// right
						grid[row][col].attach(&(grid[row][col+1]));
						// left diag
						grid[row][col].attach(&(grid[row+1][col-1]));
						// in front
						grid[row][col].attach(&(grid[row+1][col+1]));
						// left
						grid[row][col].attach(&(grid[row][col-1]));
						// right diag
						grid[row][col].attach(&(grid[row+1][col+1]));
					}
					else if ( col == 0 && (row > 0 && row < n-1) ){
						// up
						grid[row][col].attach(&(grid[row-1][col]));
						// down
						grid[row][col].attach(&(grid[row+1][col]));
						// front
						grid[row][col].attach(&(grid[row][col+1]));
						// right diag
						grid[row][col].attach(&(grid[row-1][col+1]));
						// left diag
						grid[row][col].attach(&(grid[row+1][col+1]));
					}
					else if ( row == n-1 && (col > 0 && col < n-1) ){
							// up
							grid[row][col].attach(&(grid[row-1][col]));
							// left
							grid[row][col].attach(&(grid[row][col-1]));
							// right
							grid[row][col].attach(&(grid[row][col+1]));
							// right diag
							grid[row][col].attach(&(grid[row-1][col-1]));
							// left diag
							grid[row][col].attach(&(grid[row-1][col+1]));
						}
					else if ( col == n-1 && (row > 1 && row < n-1) ){
							// up
							grid[row][col].attach(&(grid[row-1][col]));
							// front
							grid[row][col].attach(&(grid[row][col-1]));
							// below
							grid[row][col].attach(&(grid[row+1][col]));
							// right diag
							grid[row][col].attach(&(grid[row-1][col-1]));
							// left diag
							grid[row][col].attach(&(grid[row+1][col-1]));
						}
					else{
							// Has 8 neighbours
							// up
							grid[row][col].attach(&(grid[row-1][col]));
							// down
							grid[row][col].attach(&(grid[row-1][col+1]));
							// right
							grid[row][col].attach(&(grid[row-1][col-1]));
							// left
							grid[row][col].attach(&(grid[row+1][col+1]));
							// left below diag
							grid[row][col].attach(&(grid[row+1][col]));
							// right below diag
							grid[row][col].attach(&(grid[row+1][col-1]));
							// left above diag
							grid[row][col].attach(&(grid[row][col+1]));
							// right above diag
							grid[row][col].attach(&(grid[row][col-1]));
					}
				}
			}
		}
			
			initgrid = true;
		}
		else{
			initgrid = false;
			delete td;
			init(n);
		}
	}
    void Grid::turnOn( size_t r, size_t c ){  // Marks cell at row r, col c as alive.
		// Mark subject as alive
		grid[r][c].setLiving();
		td->notify(grid[r][c]);
	}
	
    void Grid::tick(){   // Next tick of the simulation.
		// Go to each cell in the grid
		for ( int row = 0; row < gridSize; ++row){
			for ( int col = 0; col < gridSize; ++col ){
				// Notify all the observers about current state
				grid[row][col].notify();
			}
		}
		for ( int row = 0; row < gridSize; ++row){
			for ( int col = 0; col < gridSize; ++col){
				grid[row][col].recalculate();
				td->notify(grid[row][col]);
			}
		}
	}
    // outputs the current grid
    std::ostream & operator<<( std::ostream & out, const Grid & g ){
		out << *(g.td);
		return out;
	}
	

