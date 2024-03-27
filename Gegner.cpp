#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cassert>
#include <assert.h>

#include "Gegner.h"
// uncomment to disable assert():
//#define NDEBUG


// Gegner ////////////////////////////////////////////////////////////////////////////

Gegner::Gegner(){

    Lebenspunkte = 1;
    x = 2;
    y = 2;
}

void Gegner::enemyMove(){
    assert(x >= 0 && x <= 4);
    assert(y >= 0 && y <= 4);

    enemy_move = rand() % 4 + 1;
    switch(enemy_move){
        case 1:
            if(y == 0){
                y = 4;
            } else {
                y -= 1;
            }
            break;
        case 2:
            if(x == 0){
                x = 4;
            } else {
                x -= 1;
            }
            break;
        case 3:
            if(y == 4){
                y = 0;
            } else {
                y += 1;
            }
            break;
        case 4:
            if(x == 4){
                x = 0;
            } else {
                x += 1;
            }
            break;
    }
}

void Gegner::enemyDamage(){
    if(Lebenspunkte > 0){
        Lebenspunkte--;
    } else {
        Lebenspunkte = 0;
    }
}

void Gegner::enemyHeal(int level){
    while(Lebenspunkte < level){
        Lebenspunkte++;
    }
}

int Gegner::get_lives(){
    return Lebenspunkte;
}

int Gegner::get_x(){
    return x;
}

int Gegner::get_y(){
    return y;
}

int Gegner::get_fight(){
    return fight;
}

int Gegner::fightSimulator(){
    fight = rand() % 6 + 1;
    return fight;
}



