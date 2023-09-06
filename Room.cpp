#include "Room.h"

/******************************************************
** function: Room:: Room();
** description: this function sets in_event and type.
** Parameters: none
** Pre-conditions: this function takes information.
** Post-conditions: this function stores in_event or type.
******************************************************/

Room::Room(){

    // event = 0;
    in_event = NULL;
    type = false;


}

void Room::get_size(int i){

cout << "Room: " << i << endl;

}

/******************************************************
** function: get_event();
** description: this function returns the event.
** Parameters: none
** Pre-conditions: this function takes in nothing.
** Post-conditions: this function returns event.
******************************************************/

char Room::get_event(){
    return event;
}

/******************************************************
** function: has_event();
** description: this function returns a true or false bool.
** Parameters: none
** Pre-conditions: this function takes type of event.
** Post-conditions: this function returns true or false.
******************************************************/

bool Room::has_event(){

    return type;

}

/******************************************************
** function: delete_event();
** description: this function deletes the precept of the event.
** Parameters: none
** Pre-conditions: this function takes in events.
** Post-conditions: this function returns events.
******************************************************/

void Room:: delete_event(){

    delete this->in_event;
    this->in_event = NULL;

    event = ' ';
    type = 0;

}

/******************************************************
** function: set_event();
** description: this function returns true or false for all events
** Parameters: none
** Pre-conditions: this function takes in nothing.
** Post-conditions: this function returns precept.
******************************************************/

bool Room::set_event(char event){


    this->event = event;

    if(event == 'w'){
        in_event = new wumpus;
        type = true;
    }
    if(event == 'b'){
        in_event = new bats;
        type = true;

    }
    if(event == 'p'){
        in_event = new pits;
        type = true;
    }
    if(event == 'g'){
        in_event = new Gold;
        type = true;
    }
    if(event == ' ' ){
        in_event = NULL;
        type = false;
    }

}

/******************************************************
** function: get_precept();
** description: this function returns the precept of the virtual name.
** Parameters: none
** Pre-conditions: this function takes in nothing.
** Post-conditions: this function returns precept.
******************************************************/

string Room:: get_precept(){

    return in_event->get_precept();

}

