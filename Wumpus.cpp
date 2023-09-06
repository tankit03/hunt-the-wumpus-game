#include "Wumpus.h"

using namespace std;

/******************************************************
** function: wumpus::wumpus();
** description: this functions is a pass through the message.
** Parameters: none
** Pre-conditions: this function sets the precept.
** Post-conditions: this stores the precept.
******************************************************/

wumpus::wumpus(){

    precept = "You smell a terrible stench.";

}


/******************************************************
** function: get_precept() const{
** description: this functions is a constructor which intalizes the value 
** Parameters: none
** Pre-conditions: this function sets values
** Post-conditions: this stores the values.
******************************************************/

string wumpus:: get_precept() const{

    return precept;

}

/******************************************************
** function: ~wumpus();
** description: this functions deletes the event 
** Parameters: none
** Pre-conditions: this function gets in nothing.
** Post-conditions: outputs nothing.
******************************************************/

wumpus:: ~wumpus(){

    // cout << "destructor" << endl;

}

