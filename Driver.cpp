/******************************************************
** Program: Driver.cpp
** Author: Tanish Hupare
** Date: 11/22/2022
** Description: the progam is a very fun game called hunt the wumpus. The player is put
** in a grid (map) which he can triver through and is supoosed to find the gold and kill
** the wumpus after that player is supposed to kill it and collect the gold and leave from
** the area they spawened in.
** Input: the input the program takes in is WASD which is supposed to help the player go through it.
** Output: the game will ouput a live grid of the map every time the player moves through the area.

******************************************************/


#include <iostream> 
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>

#include "Game.h"

using namespace std;

int main(){

    Game g;

    int play_again = 0;


    
        g.debug_mode();
        g.delete_Game();
    
   

    return 0;
}