#include "Gold.h"

using namespace std;

/******************************************************
** function: Gold::Gold();
** description: this functions is a pass through the message.
** Parameters: none
** Pre-conditions: this function sets the precept.
** Post-conditions: this stores the precept.
******************************************************/

Gold::Gold(){

 precept = "You see a glimmer nearby.";

}

/******************************************************
** function: get_precept() const{
** description: this functions is a constructor which intalizes the value 
** Parameters: none
** Pre-conditions: this function sets values
** Post-conditions: this stores the values.
******************************************************/

string Gold::get_precept() const{

    return precept;

}

/******************************************************
** function: ~Gold();
** description: this functions deletes the event 
** Parameters: none
** Pre-conditions: this function gets in nothing.
** Post-conditions: outputs nothing.
******************************************************/

Gold::~Gold(){

    // cout << "destructor" << endl;


}