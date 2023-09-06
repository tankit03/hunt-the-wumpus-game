#ifndef ROOM_H
#define ROOM_H
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Bats.h"
#include "Gold.h"
#include "Pits.h"
#include "Wumpus.h"
#include "Event.h"

using namespace std;

class Room {
    private:

        Event *in_event;
        char event;     
        bool type;
        
    public:
    Room();
    

    void get_size(int);
    char get_event();
    bool set_event(char);
    bool has_event();
    bool event_checker();
    void check_event();
    string get_precept();
    void delete_event();
};

#endif