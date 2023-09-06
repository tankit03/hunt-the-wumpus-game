#ifndef GAME_H
#define GAME_H
#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <ncurses.h>

#include "Room.h"

using namespace std;

class Game {
    private:
        vector<vector<Room>> data_cave;

        int grid_size;
        int player_debug = 0;
       

        int player_start_x;
        int player_start_y;

        int player_pos_x;
        int player_pos_y;
        int play_again;

        int wumpus_x;
        int wumpus_y;

        int gold_x;
        int gold_y;

        int arrow;

        string player_input;

        bool game_decide;
        
        int gold;
        int wumpus;




    
    public:

        Game();
        

        void set_grid_size();
        void set_room_size();
        void run_game();
        void debug_mode();
        void delete_Game();

        int random_position();
        int wumpus_rand_x();
        int wumpus_rand_y();

        void add_event_game();
        void output_map();
        void set_player_pos();
        void output_print();
        void player_movement();
        void output_adjacent();
        void arrow_hit();
        void arrow_north();
        void arrow_south();
        void arrow_east();
        void arrow_west();
        void reset_game(int);
        void Check_won();
        
        bool check_adjacent();
        bool in_grid(int, int);
        bool event_checker();

        


};

#endif