#ifndef EVENT_H
#define EVENT_H
#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>



using namespace std;

class Event {
    private:

        int location_x, location_y;
        string precept;
        char event_letter;     
    
    public:

        Event();
        ~Event();
        virtual string get_precept() const;
        virtual void output_message();

    
};

#endif