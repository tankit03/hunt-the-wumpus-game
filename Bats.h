#ifndef BATS_H
#define BATS_H
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

#include "Event.h"

class bats: public Event {
    private:

        string precept;
        
    public:

    bats();
    ~bats();
    
    string get_precept() const;

    
};

#endif