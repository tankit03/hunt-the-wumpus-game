#include "Bats.h"

using namespace std;

/******************************************************
** function: bats:: bats();
** description: this functions is a pass through the message.
** Parameters: none
** Pre-conditions: this function sets the precept.
** Post-conditions: this stores the precept.
******************************************************/

bats::bats(){

    precept = "You hear wings flapping.";

}

/******************************************************
** function: get_precept() const{
** description: this functions is a constructor which intalizes the value 
** Parameters: none
** Pre-conditions: this function sets values
** Post-conditions: this stores the values.
******************************************************/

string bats:: get_precept() const{

    return precept;

}

/******************************************************
** function: ~bat();
** description: this functions deletes the event 
** Parameters: none
** Pre-conditions: this function gets in nothing.
** Post-conditions: outputs nothing.
******************************************************/

bats::~bats(){

    // cout << "destructor" << endl;

}