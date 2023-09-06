#include "Pits.h"

using namespace std;

/******************************************************
** function: pits::pits();
** description: this functions is a pass through the message.
** Parameters: none
** Pre-conditions: this function sets the precept.
** Post-conditions: this stores the precept.
******************************************************/


pits::pits(){

    precept = "You feel a breeze.";

}

/******************************************************
** function: get_precept() const{
** description: this functions is a constructor which intalizes the value 
** Parameters: none
** Pre-conditions: this function sets values
** Post-conditions: this stores the values.
******************************************************/

string pits:: get_precept() const{

    return precept;

}

/******************************************************
** function: ~pits();
** description: this functions deletes the event 
** Parameters: none
** Pre-conditions: this function gets in nothing.
** Post-conditions: outputs nothing.
******************************************************/

pits::~pits(){

    // cout << "destructor" << endl;

}
