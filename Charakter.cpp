#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cassert>
#include <assert.h>

#include "Charakter.h"
// uncomment to disable assert():
//#define NDEBUG


// Charakter //////////////////////////////////////////////////////////////////////

Charakter::Charakter(){

    Lebenspunkte = 5;
    Reliktpunkte = 0;
    x = 0;
    y = 0;

    Staerke = rand() % 10 + 1;
    Schnelligkeit = rand() % 10 + 1;
    Klugheit = rand() % 10 + 1;

    Fitness = 0;
    RedBull = 0;
    Buch = 0;
}

void Charakter::printHero(){
    assert(Lebenspunkte >= 0);
    assert(Reliktpunkte >= 0);
    assert(x >= 0 && x <= 4);
    assert(y >= 0 && y <= 4);
    assert(Staerke >= 0);
    assert(Schnelligkeit >= 0);
    assert(Klugheit >= 0);

    std::cout << "Leben: " << Lebenspunkte << std::endl;
    std::cout << "Relikte gefunden: " << Reliktpunkte << std::endl;
    std::cout << "X-Koordinate: " << x << std::endl;
    std::cout << "Y-Koordinate: " << y << std::endl;
    std::cout << "Staerke: " << Staerke << std::endl;
    std::cout << "Schnelligkeit: " << Schnelligkeit << std::endl;
    std::cout << "Klugheit: " << Klugheit << std::endl;
    std::cout << "Fitness: " << Fitness << std::endl;
    std::cout << "RedBull: " << RedBull << std::endl;
    std::cout << "Buch: " << Buch << std::endl;
}

int Charakter::playerMove(){
    assert(x >= 0 && x <= 4);
    assert(y >= 0 && y <= 4);

    // read-in user input to move the character
    std::cin >> player_move;
    false_command = 0;

    // move the character according to the user's input
    switch(player_move){
        case 'w':
            if(y == 0){
                y = 4;
            } else {
                y -= 1;
            }
            break;
        case 'a':
            if(x == 0){
                x = 4;
            } else {
                x -= 1;
            }
            break;
        case 's':
            if(y == 4){
                y = 0;
            } else {
                y += 1;
            }
            break;
        case 'd':
            if(x == 4){
                x = 0;
            } else {
                x += 1;
            }
            break;
        default:
            false_command = 1;
    }
    return false_command;
}

void Charakter::playerDamage(){
    if(Lebenspunkte > 0){
        Lebenspunkte--;
    } else {
        Lebenspunkte = 0;
    }
}

void Charakter::playerHeal(){
    Lebenspunkte++;
}

int Charakter::get_x(){
    return x;
}

int Charakter::get_y(){
    return y;
}

int Charakter::get_lives(){
    return Lebenspunkte;
}

int Charakter::dangerSimulator(){
    damage = 0;
    prob_danger = rand() % 10 + 1;
    dangerType = rand() % 3 + 1;
    switch(dangerType){
        case 1:
            if(prob_danger >= Staerke){
                if(Fitness > 0){
                    Fitness--;
                    damage = 0;
                } else {
                    damage = 1;
                }
            }
            break;
        case 2:
            if(prob_danger >= Schnelligkeit){
                if(RedBull > 0){
                    RedBull--;
                    damage = 0;
                } else {
                    damage = 2;
                }
            }
            break;
        case 3:
            if(prob_danger >= Klugheit){
                if(Buch > 0){
                    Buch--;
                    damage = 0;
                } else {
                    damage = 3;
                }
            }
            break;
    }
    return damage;
}

void Charakter::increaseRelicpoints(){
    Reliktpunkte++;
}

int Charakter::get_item(){
    prob_item = rand() % 5 + 1;
    if(prob_item == 1){
        itemType = rand() % 3 + 1;
        switch(itemType){
            case 1:
                Fitness++;
                break;
            case 2:
                RedBull++;
                break;
            case 3:
                Buch++;
                break;
        }
    } else {
        itemType = 0;
    }
    return itemType;
}
