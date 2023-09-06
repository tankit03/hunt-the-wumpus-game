#include "Event.h"

using namespace std;

/******************************************************
** function: Event::Event();
** description: this functions is a constructor which intalizes the value 
** Parameters: none
** Pre-conditions: this function sets values
** Post-conditions: this stores the values.
******************************************************/

Event::Event(){

    precept = " ";
    event_letter = ' ';

}

/******************************************************
** function: get_precept();
** description: this function returns the precept of the virtual name.
** Parameters: none
** Pre-conditions: this function takes in nothing.
** Post-conditions: this function returns precept.
******************************************************/

string Event::get_precept() const{

    return precept;

}

/******************************************************
** function: get_precept();
** description: this function returns the precept of the virtual name.
** Parameters: none
** Pre-conditions: this function takes in nothing.
** Post-conditions: this function returns precept.
******************************************************/

void Event::output_message(){

    cout << precept << endl;

}

/******************************************************
** function: ~Event();
** description: this acts as a destructor.
** Parameters: none
** Pre-conditions: this takes in nothing.
** Post-conditions: returns the destructor.
******************************************************/

Event:: ~Event(){

    cout << "destructor" << endl;

}