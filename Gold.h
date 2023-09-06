#ifndef GOLD_H
#define GOLD_H
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Event.h"

using namespace std;

class Gold : public Event {
    private:

    string precept;


    public:

    Gold();
    ~Gold();
    string get_precept() const;

    
};

#endif