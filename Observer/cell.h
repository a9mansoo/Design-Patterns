#ifndef CELL_H
#define CELL_H
#include <cstddef> // defines size_t i.e. an unsigned int
#include <iostream>
#include "subject.h"
#include "observer.h"
#include "info.h"
#include <vector>

class Cell : public Subject, public Observer {
  private:
    bool Alive; // Current state of the cell object
    Info info; // Current info of the cell
    int neighbours; // A count of neighbours that are alive
   // Observers are all the cells next to our current cell object 3-8
  public:
    Cell(size_t r, size_t c);
    void setLiving(); // Marks cell as alive.
    void reset(); // Resets neighbour count to 0.

    // Grid calls this to get me to notify my neighbours if I'm alive.
    // Also needs to be called when state is set to be alive so displays are notified.
    virtual void notify() override;

    // My neighbours will call this to let me know if they're alive.
    void notify( Subject & whoNotified ) override;
                                                
    // Reassess my living-or-dead status, based on info from neighbours.
    void recalculate(); 

    // Observer calls this to get information about cell.
    virtual Info getInfo() const override;
};

#endif



