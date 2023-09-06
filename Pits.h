#ifndef PITS_H
#define PITS_H
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

#include "Event.h"

class pits: public Event {
    private:
    
        string precept;

    public:

    pits();
    ~pits();
    
    string get_precept() const;


};

#endif