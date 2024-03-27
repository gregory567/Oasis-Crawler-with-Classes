#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cassert>
#include <assert.h>


#include "Spielwelt.h"
#include "Charakter.h"
#include "Gegner.h"
#include "Spielverlauf.h"

#include "Spielwelt.cpp"
#include "Charakter.cpp"
#include "Gegner.cpp"
#include "Spielverlauf.cpp"
// uncomment to disable assert():
//#define NDEBUG


int main(){

    /* GAME PREPARATION */

    // use the current time as seed for the random generator
    srand(time(NULL));

    // generate the game field
    Spielwelt field;

    // set the lives of the hero to 5 and the number of collectible items to 0
    // set the starting point of the hero to the coordinates x:0, y:0
    Charakter hero;

    // set the lives of the enemies to 1 and their starting point to the coordinates x:2, y:2
    Gegner enemy_1;
    Gegner enemy_2;

    // set the game summary class
    Spielverlauf stats;

    std::cout << "Relikte zu finden: " << field.countHiddenRelics() << std::endl;
    hero.printHero();
    field.printField(stats.get_level());

    /* GAME */
    do{

        if(hero.playerMove() == 1){
            std::cout << "Falscher Befehl!" << std::endl;
            continue;
        }

        // increase the number of rounds by 1 at the start of each round
        stats.increaseRound();

        // manipulate the fields, lives of the hero and the number of relics found and hidden
        // if the hero steps on an empty field nothing happens
        if(field.get_tile(hero.get_x(), hero.get_y()) >= 1 && field.get_tile(hero.get_x(), hero.get_y()) < 4 - stats.get_level() * 0.8){
            field.set_tile_empty(hero.get_x(), hero.get_y());
        // if the hero steps on a dangerous field decrease his life points
        } else if(field.get_tile(hero.get_x(), hero.get_y()) >= 4 - stats.get_level() * 0.8 && field.get_tile(hero.get_x(), hero.get_y()) < 8 + stats.get_level() * 0.3){
            switch(hero.dangerSimulator()){
                case 0:
                    break;
                case 1:
                    hero.playerDamage();
                    stats.createStat("Staerke");
                    break;
                case 2:
                    hero.playerDamage();
                    stats.createStat("Schnelligkeit");
                    break;
                case 3:
                    hero.playerDamage();
                    stats.createStat("Klugheit");
                    break;
            }

            field.set_tile_empty(hero.get_x(), hero.get_y());
        // if the hero steps on a field with a life-fountain increase his life points by 1
        } else if(field.get_tile(hero.get_x(), hero.get_y()) >= 8 + stats.get_level() * 0.3 && field.get_tile(hero.get_x(), hero.get_y()) < 9){
            hero.playerHeal();
            switch(hero.get_item()){
                case 0:
                    break;
                case 1:
                    stats.createStat("Fitness");
                    break;
                case 2:
                    stats.createStat("RedBull");
                    break;
                case 3:
                    stats.createStat("Buch");
                    break;
            }
            stats.createStat("Quelle");
            field.set_tile_empty(hero.get_x(), hero.get_y());
        // if the hero steps on a field with a relic increase number of found relics
        } else if(field.get_tile(hero.get_x(), hero.get_y()) >= 9){
            hero.increaseRelicpoints();
            switch(hero.get_item()){
                case 0:
                    break;
                case 1:
                    stats.createStat("Fitness");
                    break;
                case 2:
                    stats.createStat("RedBull");
                    break;
                case 3:
                    stats.createStat("Buch");
                    break;
            }
            stats.createStat("Relikt");
            field.set_tile_empty(hero.get_x(), hero.get_y());
        }

        // move enemy 1 automatically every round after the hero moved
        // enemy's movement is based on random number generation
        if(enemy_1.get_lives() > 0){
            enemy_1.enemyMove();
            if(enemy_1.get_x() == hero.get_x() && enemy_1.get_y() == hero.get_y()){
                enemy_1.fightSimulator();
                if(1 <= enemy_1.get_fight() && enemy_1.get_fight() <= 3){
                    enemy_1.enemyDamage();
                    stats.createStat("Sieg");
                } else {
                    hero.playerDamage();
                    stats.createStat("Gegner");
                }
            }
        }

        // move enemy 2 automatically every round after the hero moved
        // enemy's movement is based on random number generation
        if(enemy_2.get_lives() > 0){
            enemy_2.enemyMove();
            if(enemy_2.get_x() == hero.get_x() && enemy_2.get_y() == hero.get_y()){
                enemy_2.fightSimulator();
                if(1 <= enemy_2.get_fight() && enemy_2.get_fight() <= 3){
                    enemy_2.enemyDamage();
                    stats.createStat("Sieg");
                } else {
                    hero.playerDamage();
                    stats.createStat("Gegner");
                }
            }
        }

        // print basic stats in each round
        std::cout << "Runde: " << stats.get_round_counter() << std::endl;
        std::cout << "Relikte zu finden: " << field.countHiddenRelics() << std::endl;
        hero.printHero();
        field.printField(stats.get_level());

        if(field.countHiddenRelics() == 0){
            stats.level_up();
            // regenerate the game field
            field.regenerateField();
            enemy_1.enemyHeal(stats.get_level());
            enemy_2.enemyHeal(stats.get_level());

            // print basic stats again
            std::cout << "Level Up!" << std::endl;
            std::cout << "Level: " << stats.get_level() + 1 << std::endl;
            std::cout << "Runde: " << stats.get_round_counter() << std::endl;
            std::cout << "Relikte zu finden: " << field.countHiddenRelics() << std::endl;
            hero.printHero();
            field.printField(stats.get_level());
        }

    }while(hero.get_lives() > 0 && stats.get_level() < 4);

    if(stats.get_level() == 0){
        std::cout << "Du hast das erste Level erreicht, Gratulation!" << std::endl;
    } else if(stats.get_level() == 1){
        std::cout << "Du hast das zweite Level erreicht, Gratulation!" << std::endl;
    } else if(stats.get_level() == 2){
        std::cout << "Du hast das dritte Level erreicht, Gratulation!" << std::endl;
    } else if(stats.get_level() == 3){
        std::cout << "Du hast das vierte Level erreicht, Gratulation!" << std::endl;
    } else if(stats.get_level() == 4){
        std::cout << "Du hast das Spiel gewonnen, Gratulation!" << std::endl;
    }

    // print summary stats at the end of the game
    stats.printStats();

    return 0;
}

