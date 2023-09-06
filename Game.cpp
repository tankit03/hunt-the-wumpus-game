#include "Game.h"
#include "Room.h"
#include <vector>

#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <ncurses.h>
using namespace std;

/******************************************************
** function: Game::Game();
** description: this functions is a crunstructor for the game.cpp and sets all the int and values to 0.
** Parameters: none
** Pre-conditions: this functions needs the values be declared first
** Post-conditions: functions intinzalies the values.
******************************************************/

Game::Game(){

grid_size = 0;
player_start_x = 0;
player_start_y = 0;
player_pos_x = 0;
player_pos_y = 0;

wumpus_x = 0;
wumpus_y = 0;

gold_x = 0;
gold_y = 0;


arrow = 3;

player_input;
play_again = 0;

game_decide = 1;
gold = 0;
wumpus = 1;


}

void Game:: delete_Game(){
    

    for(int i = 0; i < grid_size; i++){

        for(int j = 0; j <grid_size; j++){

            //if(data_cave[i][j].has_event() == true){

                data_cave[i][j].delete_event();
            //}

        }
    }

}


/******************************************************
** function: set_grid_size();
** description: this functions takes in the players 
** grid size and also error heandles for it
** Parameters: none
** Pre-conditions: this functions needs the values be declared first.
** Post-conditions: functions stores the grid_size value.
******************************************************/

void Game::set_grid_size(){

cout << "Enter the grid size you want to play with: ";
cin >> grid_size;

    while(grid_size <= 4){

        cout << "This map is too small, please input a larger grid size: ";
        cin >> grid_size;
    }
}

/******************************************************
** function: set_room_size();
** description: this functions creates a 2d-vector of the room size from the player.
** Parameters: none
** Pre-conditions: this functions needs the values be declared first.
** Post-conditions: functions stores the vector value and helps create the grid.
******************************************************/

void Game::set_room_size(){

    vector<vector<Room>> data(grid_size, vector<Room>(grid_size));

    data_cave = data;

    cout << endl << "A " << data.size() << "x" << data[0].size() << " matrix" << endl;
}

/******************************************************
** function: random_position();
** description: this functions creates a random value and returns it.
** Parameters: none
** Pre-conditions: this functions needs the values be declared first.
** Post-conditions: functions returns the num of the random value.
******************************************************/

int Game::random_position(){

    int num = rand() % grid_size;
    return num;

}

/******************************************************
** function: set_player_pos();
** description: this functions sets the player start to random_position().
** Parameters: none
** Pre-conditions: this functions needs the values be declared first.
** Post-conditions: functions sets the player to a random_positions on the grid.
******************************************************/

void Game::set_player_pos(){

    srand(time(NULL)); 
  

    player_start_x = player_pos_x = random_position();

    player_start_y = player_pos_y = random_position();

    

}

/******************************************************
** function: wumpus_rand_x();
** description: this functions returns the wumpus x postions
** Parameters: none
** Pre-conditions: this functions needs the values be declared first.
** Post-conditions: functions returns the wumpus_x value.
******************************************************/

int Game:: wumpus_rand_x(){

    wumpus_x = random_position();
    return wumpus_x;
}

/******************************************************
** function: wumpus_rand_y();
** description: this functions returns the wumpus y postions
** Parameters: none
** Pre-conditions: this functions needs the values be declared first.
** Post-conditions: functions returns the wumpus_y value.
******************************************************/

int Game:: wumpus_rand_y(){

    wumpus_y = random_position();
    return wumpus_y;

}

/******************************************************
** function: output_print();
** description: this functions creates a 2d-vector of the room size from the player.
** Parameters: none
** Pre-conditions: this functions outputs the w,a,s,d options.
** Post-conditions: functions stores w,a,s,d.
******************************************************/

void Game::output_print(){

    cout << "type w to go forward" << endl;
    cout << "type a to go left" << endl;
    cout << "type d to go right" << endl;
    cout << "type s to go backward" << endl;
    cout << "type ' ' to shoot arrow, then you will be prompted again with (WASD) to shoot" << endl;
    
    system("stty -echo");
    system("stty cbreak");

    player_input = getchar();

    system ("stty echo");
    system ("stty -cbreak");   

}

/******************************************************
** function: player_movement();
** description: this functions creates a 2d-vector of the room size from the player.
** Parameters: none
** Pre-conditions: this first needs the player_input and stores that value.
** Post-conditions: functions moves that player through the map.
******************************************************/

void Game:: player_movement(){

    output_print();

    if((player_input == "w") && (in_grid(player_start_x-1, player_start_y) == true)){

        player_start_x = player_start_x - 1;
        
    }
    if((player_input == "s") && (in_grid(player_start_x+1, player_start_y) == true)){


        player_start_x = player_start_x + 1;
    
    }
    if((player_input == "a") && ((in_grid(player_start_x, player_start_y-1) == true))){

        player_start_y = player_start_y - 1;
            
    }if((player_input == "d") && (in_grid(player_start_x, player_start_y+1) == true)){

        player_start_y = player_start_y + 1;  
        
    }
    if(player_input == " "){
        
        if(arrow > 0){

            cout << "This is the current amount of arrow's: " << arrow << endl;
            arrow_hit();

        }else{

            cout << "you don't have any arrow's left" << endl;
        }
    } 
}

/******************************************************
** function: arrow_hit();
** description: this functions helps get input for the arrow shot.
** Parameters: none
** Pre-conditions: this functions needs other values to be declared and then also 
** stores that information into this function.
** Post-conditions: the functions helps prints the functions to and also decrease arrow.
******************************************************/

void Game:: arrow_hit(){



    output_print();

    if(player_input == "w"){
        
        arrow_north();

        arrow--;
    }
    if(player_input == "s"){
            
        arrow_south();

        arrow--;
    }
    if(player_input == "a"){
            
        arrow_east();
        
        arrow--;
    }
    if(player_input == "d"){
            
        arrow_west();
        
        arrow--;
    }

}

/******************************************************
** function: arrow_north();
** description: this functions moves the arrow and check if hit wumpus and also if it hit the wall
** Parameters: none
** Pre-conditions: this first needs the player_input and also the 2d vector information to move.
** Post-conditions: functions tells the player if they hit a wall or wumpus.
******************************************************/

void Game:: arrow_north(){

        if((player_start_x < grid_size)){

            for(int i = 0; i < 4; i++){
                
                if((in_grid(player_start_x-i, player_start_y) == true)){
        
                    if((data_cave[player_start_x-i][player_start_y].has_event() == true)){
                        cout << "hello" << endl;

                        if((data_cave[player_start_x-i][player_start_y].get_event() == 'w')){
                            wumpus--;
                            cout << "wumpus after being shot: " << wumpus << endl;
                            cout << "You have slayed the wumpus!!" << endl;
                            data_cave[player_start_x-i][player_start_y].set_event(' ');
                            
                        }
                    }
                }else{
                    cout << "You missed the wumpus" << endl;
                }
            }   

            cout << "wumpus being shot: " << wumpus << endl;

            if(wumpus == 1){

                data_cave[wumpus_x][wumpus_y].delete_event(); 

                srand(time(NULL));
                int switch_x = rand() % 4;
                int switch_y = rand() % 4;  

                wumpus_x = switch_x;
                wumpus_y = switch_y;  

                cout << "The Wumpus has moved" << endl;
                data_cave[switch_x][switch_y].set_event('w');
                
                
            }            
        }  
}

/******************************************************
** function: arrow_south();
** description: this functions moves the arrow and check if hit wumpus and also if it hit the wall
** Parameters: none
** Pre-conditions: this first needs the player_input and also the 2d vector information to move.
** Post-conditions: functions tells the player if they hit a wall or wumpus.
******************************************************/

void Game:: arrow_south(){

   

    if(player_start_x < grid_size){

        for(int i = 0; i < 4; i++){

            if((in_grid(player_start_x+i, player_start_y) == true)){

                if(data_cave[player_start_x+i][player_start_y].has_event() == true){
                    
                    if(data_cave[player_start_x+i][player_start_y].get_event() == 'w'){
                        wumpus = 0;
                        cout << "You have slayed the wumpus!!" << endl;
                        data_cave[player_start_x+i][player_start_y].set_event(' ');
                    }
                }
            }else{
                cout << "You missed the wumpus" << endl;
            }
        }
        if(wumpus == 1){

            data_cave[wumpus_x][wumpus_y].delete_event(); 
            cout << "haha" << endl;
            srand(time(NULL));
            int switch_x = rand() % 4;
            int switch_y = rand() % 4;    

            wumpus_x = switch_x;
            wumpus_y = switch_y;

            cout << "The Wumpus has moved" << endl;
            data_cave[switch_x][switch_y].set_event('w');
        }    
    }   
}
/******************************************************
** function: arrow_east();
** description: this functions moves the arrow and check if hit wumpus and also if it hit the wall
** Parameters: none
** Pre-conditions: this first needs the player_input and also the 2d vector information to move.
** Post-conditions: functions tells the player if they hit a wall or wumpus.
******************************************************/

void Game:: arrow_east(){

    if(player_start_x < grid_size){

        for(int i = 0; i < 4; i++){

            if((in_grid(player_start_x, player_start_y-i) == true)){
                
                if(data_cave[player_start_x][player_start_y-i].has_event() == true){
                    if(data_cave[player_start_x][player_start_y-i].get_event() == 'w'){
                        wumpus = 0;
                        cout << "You have slayed the wumpus!!" << endl;
                        data_cave[player_start_x][player_start_y-i].set_event(' ');
                    }
                }
            }else{

                cout << "You missed the wumpus" << endl;
            }
        }

        if(wumpus == 1){

                data_cave[wumpus_x][wumpus_y].delete_event(); 
                srand(time(NULL));
                int switch_x = rand() % 4;
                int switch_y = rand() % 4;    
                
                wumpus_x = switch_x;
                wumpus_y = switch_y;

                cout << "The Wumpus has moved" << endl;
                data_cave[switch_x][switch_y].set_event('w');
        } 
    }

}

/******************************************************
** function: arrow_west();
** description: this functions moves the arrow and check if hit wumpus and also if it hit the wall
** Parameters: none
** Pre-conditions: this first needs the player_input and also the 2d vector information to move.
** Post-conditions: functions tells the player if they hit a wall or wumpus.
******************************************************/

void Game:: arrow_west(){

    
    if(player_start_x < grid_size){

        for(int i = 0; i < 4; i++){

            if((in_grid(player_start_x, player_start_y+i) == true)){

                if(data_cave[player_start_x][player_start_y+i].has_event() == true){
                    if(data_cave[player_start_x][player_start_y+i].get_event() == 'w'){
                        wumpus = 0;
                        cout << "You have slayed the wumpus!!" << endl;
                        data_cave[player_start_x][player_start_y+i].set_event(' ');
                    }
                }
            }else{
                cout << "You missed the wumpus" << endl;
            }
        }
        if(wumpus == 1){

            data_cave[wumpus_x][wumpus_y].delete_event(); 
            srand(time(NULL));
            int switch_x = rand() % 4;
            int switch_y = rand() % 4;

            wumpus_x = switch_x;
            wumpus_y = switch_y;

            cout << "The Wumpus has moved" << endl;
            data_cave[switch_x][switch_y].set_event('w');
        } 
    }
}

/******************************************************
** function: add_event_game();
** description: this sets the all the events in the play game function.
** Pre-Conditions: needs the vector size and also the needs to pull the set event principle.
** Post-conditions: This function sets the event in the post.
******************************************************/

void Game::add_event_game(){

    srand(time(NULL));


    data_cave[wumpus_rand_x()][wumpus_rand_y()].set_event('w');

    data_cave[random_position()][random_position()].set_event('p');
    data_cave[random_position()][random_position()].set_event('p');

    data_cave[random_position()][random_position()].set_event('b');
    data_cave[random_position()][random_position()].set_event('b');

    data_cave[random_position()][random_position()].set_event('g');

}

/******************************************************
** function: event_checker();
** description: this functions checks the event outputs if you go intro the room.
** Parameters: none
** Pre-conditions: takes a bool value from true and false.
** Post-conditions: the function returns the game_decide true or false.
******************************************************/

bool Game::event_checker(){

    srand(time(NULL));

    player_start_x;
    player_start_y;

    if(data_cave[player_start_x][player_start_y].has_event() == true){

        if((data_cave[player_start_x][player_start_y].get_event() == 'w')){

            cout << "You have entered the room that the Wumpus is sleeping in, you just woke him up! just like that he ate you" << endl;
            game_decide = false;
                    
        }
        else if((data_cave[player_start_x][player_start_y].get_event() == 'p')){

            cout << "The pit has consumed you, you will adopt the dark" << endl;
            game_decide = false;
                    
        }
        else if((data_cave[player_start_x][player_start_y].get_event() == 'g')){

            cout << "You have found the gold" << endl;
            gold++;
            data_cave[player_start_x][player_start_y].set_event(' ');
                    
        }
        else if(data_cave[player_start_x][player_start_y].get_event() == 'b'){

            cout << "You have walked into a room with bats, they've taken you to a new place" << endl;

            player_start_x = random_position();
            player_start_y = random_position();

        }
    }
} 


/******************************************************
** function: output_map();
** description: this functions outputs the the grid with collum and rows.
** Parameters: none
** Pre-conditions: this first needs the player_input and stores that value.
** Post-conditions: functions moves that player through the map.
******************************************************/




void Game::output_map(){

    for(int i = 0; i < grid_size; i++){

        for(int j = 0; j <grid_size; j++){
            
            if((player_start_x == i) && (player_start_y == j)){

                cout << "| * ";
            
            }
            else if((data_cave[i][j].has_event() == true) && (player_debug == 1)){


                cout << "| " << data_cave[i][j].get_event() << " ";
                

            }else{

                cout <<"|   ";
            }
        }
        cout << endl;
        for(int i = 0; i <grid_size; i++){
                
                cout << "____";
        }

        cout << endl;
        
    }

}

/******************************************************
** function: in_grid(int,int);
** description: this functions creates a 2d-vector of the room size from the player.
** Parameters: x_point, y_point
** Pre-conditions: this function takes in the grid_size value and all.
** Post-conditions: functions retruns true or false if it's in grid or not.
******************************************************/

bool Game::in_grid(int x_point, int y_point){


    if((x_point > grid_size-1) || (x_point < 0) || (y_point > grid_size-1) || (y_point < 0)){

        return false;

    }else{

        return true;
    }

}

/******************************************************
** function: output_adjacent();
** description: this functions creates a 2d-vector of the room size from the player.
** Parameters: none
** Pre-conditions: this function takes in the value of data cave.
** Post-conditions: this functions ouputs the message if the player is close to it.
******************************************************/


void Game::output_adjacent(){

    
        if(player_start_x > 0){

            if((data_cave[player_start_x-1][player_start_y].has_event() != 0)){
                cout << data_cave[player_start_x-1][player_start_y].get_precept() << endl << endl;
            }
        }

        if(player_start_x < grid_size-2){
            
            if((data_cave[player_start_x+1][player_start_y].has_event() != 0)){
                cout << data_cave[player_start_x+1][player_start_y].get_precept() << endl << endl;
            
            }  
        }

        if(player_start_y > 0){

            if((data_cave[player_start_x][player_start_y-1].has_event() != 0)){
                cout << data_cave[player_start_x][player_start_y-1].get_precept() << endl << endl;
            }   
        }

        if(player_start_y < grid_size-2){
            if((data_cave[player_start_x][player_start_y+1].has_event() != 0)){
                cout << data_cave[player_start_x][player_start_y+1].get_precept() << endl << endl;
            }   
        }    

}

/******************************************************
** function: check_won();
** description: this function checks if the player wins the game or not.
** Parameters: none
** Pre-conditions: requires the values gold wumpus.
** Post-conditions: tells if the player won or not.
******************************************************/

void Game::Check_won(){

   if((gold == 1) && (wumpus == 0) && (player_start_x == player_pos_x) && (player_start_y == player_pos_y)){

    cout << "You won the game!! you killed the wumpus, collected the gold and left through the rope" << endl;
    game_decide = false;

   }
   if(arrow == 0){
       cout << "You have ran out of arrow's" << endl;
       game_decide = false;
   }
}

/******************************************************
** function: reset_game(int);
** description: this function resets the game with the same map and output grid.
** Parameters: play_again
** Pre-conditions: this first needs the player_again and stores that value.
** Post-conditions: functions returns true or false 
******************************************************/

void Game:: reset_game(int play_again){


    if(play_again == 1){

        set_player_pos();

        if(wumpus == 0){
    
            data_cave[wumpus_x][wumpus_y].set_event('w');

        }else if(gold == 1){

            data_cave[gold_x][gold_y].set_event('g');

        }

        wumpus = 1;
        gold = 0;
        arrow = 3;
        play_again = 0;
        game_decide = 1;

    }
    if(play_again == 2){

        wumpus = 1;
        gold = 0;
        arrow = 3;
        play_again = 0;
        game_decide = true;

    }
}

/******************************************************
** function: debug_mode();
** description: this functions gives the player an option debug_mode or play game with hidden event.
** Parameters: none
** Pre-conditions: this requires the run_game(); and also the entire run game without event.
** Post-conditions: function is a void and plays through the game.
******************************************************/

void Game:: debug_mode(){


    cout << "Do you want to play the game in debug mode(0-no 1-yes): ";
    cin >> player_debug;

    while(player_debug >= 2){

        cout << "please input the right debug: ";
        cin >> player_debug;

    }

    if(player_debug == 1){
        run_game();
        
    }
    else if(player_debug == 0){

    cout << player_debug << endl;

    do{
        set_grid_size();
        set_room_size();
        add_event_game();
        set_player_pos();

            do{
                
                do{

                    player_movement();
                    event_checker();
                    output_adjacent();
                    output_map();
                            

                    cout << endl;
                    cout << "Gold collected: " << gold << endl;
                    cout << "How many Wumpus are left: " << wumpus << endl;
                    cout << "this is how many arrow left: " << arrow << endl << endl;
                 
                    Check_won();

                }while(game_decide == 1);
                
                cout << endl;
                cout << "Do you want start game from where you died (1) or start game from start (2)";
                cin >> play_again;
                cout << play_again << endl;
                reset_game(play_again);

            }while(play_again == 1);

        
    }while(play_again == 2);

        

    }
}

/******************************************************
** function: run_game();
** description: this functions through the entire game and all the functions.
** Parameters: none
** Pre-conditions: this functions takes in all the functions.
** Post-conditions: functions plays through the entire game.
******************************************************/

void Game::run_game(){

    
    do{
        set_grid_size();
        set_room_size();
        set_player_pos();
        add_event_game();

        cout << endl;
    

        do{
            output_map();
        
            do{

                player_movement();
                event_checker();
                output_adjacent();
                output_map();
            

                cout << endl;
                cout << "Gold collected: " << gold << endl;
                cout << "How many Wumpus are left: " << wumpus << endl;
                cout << "this is how many arrow left: " << arrow << endl << endl;
                cout << "this is the game decide: " << game_decide << endl;
                Check_won();
                
            }while(game_decide == 1);

            cout << endl;
            cout << "Do you want start game with same map (1), start game with a new map (2) or end game (3): ";
            cin >> play_again;
            reset_game(play_again);

        }while(play_again == 1);

        reset_game(play_again);

    }while(play_again == 2);
}