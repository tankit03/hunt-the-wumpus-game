#ifndef WUMPUS_H
#define WUMPUS_H
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Event.h"

using namespace std;

class wumpus: public Event {
    private:

    string precept;
        
    public:

    
    wumpus();
    ~wumpus();
    
    string get_precept() const;

    
};

#endif