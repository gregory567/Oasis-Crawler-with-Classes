#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cassert>
#include <assert.h>

#include "Spielwelt.h"
// uncomment to disable assert():
//#define NDEBUG


// Spielfeld //////////////////////////////////////////////////////////////////////////////////

Spielwelt::Spielwelt(){
    low = 1;
    high = 10;
    // generate a game field with the condition that there has to be at least one relic hidden on it
    relic_counter = 0;
    do{
        // fill the game 5 by 5 field with randomly generated integers between 1 and 10
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                twod_world[i][j] = low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
            }
        }

        // check if there is at least one relic hidden on the field
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                if(twod_world[i][j] >= static_cast<float>(9)){
                    relic_counter++;
                }
            }
        }
    }while(relic_counter == 0);
}

void Spielwelt::printField(int level){
    // print the field
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            // if the enemy should be displayed uncomment the following lines
            /*
            if(enemy_1.get_lives() > 0 && i == enemy_1.get_y() && j == enemy_1.get_x()){
                cout << "G ";
                continue;
            }

            if(enemy_2.get_lives() > 0 && i == enemy_2.get_y() && j == enemy_2.get_x()){
                cout << "G ";
                continue;
            }
            */
            assert(twod_world[i][j] >= static_cast<float>(1) && twod_world[i][j] <= static_cast<float>(10));

            if(twod_world[i][j] >= static_cast<float>(1) && twod_world[i][j] < static_cast<float>(4 - level * 0.8)){
                std::cout << "E ";
            } else if(twod_world[i][j] >= static_cast<float>(4 - level * 0.8) && twod_world[i][j] < static_cast<float>(8 + level * 0.3)){
                std::cout << "D ";
            } else if(twod_world[i][j] >= static_cast<float>(8 + level * 0.3) && twod_world[i][j] < static_cast<float>(9)){
                std::cout << "Q ";
            } else if(twod_world[i][j] >= static_cast<float>(9)){
                std::cout << "R ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int Spielwelt::countHiddenRelics(){
    relic_counter = 0;
    // count the number of relics present on the field
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            assert(twod_world[i][j] >= static_cast<float>(1) && twod_world[i][j] <= static_cast<float>(10));
            if(twod_world[i][j] >= static_cast<float>(9)){
                relic_counter++;
            }
        }
    }
    return relic_counter;
}

int Spielwelt::get_tile(int x, int y){
    return twod_world[y][x];
}

void Spielwelt::set_tile_empty(int x, int y){
    twod_world[y][x] = 1;
}

void Spielwelt::regenerateField(){
    // generate a game field with the condition that there has to be at least one relic hidden on it
    relic_counter = 0;
    do{
        // fill the game 5 by 5 field with randomly generated integers between 1 and 10
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                twod_world[i][j] = low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
            }
        }

        // check if there is at least one relic hidden on the field
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                if(twod_world[i][j] >= static_cast<float>(9)){
                    relic_counter++;
                }
            }
        }
    }while(relic_counter == 0);
}



