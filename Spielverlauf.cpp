#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cassert>
#include <assert.h>
#include <string.h>


#include "Spielverlauf.h"
// uncomment to disable assert():
//#define NDEBUG

// Spielverlauf ///////////////////////////////////////////////////////////////////////////

Spielverlauf::Spielverlauf(){
    round_counter = 0;
    event_counter = 0;
    events[event_counter] = {0, "Spielstart!"};
    level = 0;
}

void Spielverlauf::increaseRound(){
    round_counter++;
}

int Spielverlauf::get_round_counter(){
    return round_counter;
}

void Spielverlauf::level_up(){
    level++;
}

int Spielverlauf::get_level(){
    return level;
}

void Spielverlauf::createStat(const char* highlight){
    event_counter++;
    if(strcmp(highlight, "Staerke") == 0){
        events[event_counter] = {round_counter, "Du warst zu schwach und hast deswegen Schaden erlitten!"};
    } else if(strcmp(highlight, "Schnelligkeit") == 0){
        events[event_counter] = {round_counter, "Du warst zu langsam und hast deswegen Schaden erlitten!"};
    } else if(strcmp(highlight, "Klugheit") == 0){
        events[event_counter] = {round_counter, "Du warst zu dumm und hast deswegen Schaden erlitten!"};
    } else if(strcmp(highlight, "Fitness") == 0){
        events[event_counter] = {round_counter, "Du warst im Fitnessstudio! Du bist jetzt staerker!"};
    } else if(strcmp(highlight, "RedBull") == 0){
        events[event_counter] = {round_counter, "Du hast ein RedBull gefunden! Du hast jetzt Fluegel!"};
    } else if(strcmp(highlight, "Buch") == 0){
        events[event_counter] = {round_counter, "Du hast endlich einmal ein Buch gelesen! Du bist klüger geworden!"};
    } else if(strcmp(highlight, "Quelle") == 0){
        events[event_counter] = {round_counter, "Du hast eine Quelle gefunden, Leben erhalten!"};
    } else if(strcmp(highlight, "Relikt") == 0){
        events[event_counter] = {round_counter, "Du hast ein Relikt gefunden!"};
    } else if(strcmp(highlight, "Gegner") == 0){
        events[event_counter] = {round_counter, "Du hast Schaden durch Gegner erlitten!"};
    } else if(strcmp(highlight, "Sieg") == 0){
        events[event_counter] = {round_counter, "Du hast einen Gegner besiegt!"};
    }
}


void Spielverlauf::printStats(){

    std::cout << "Spielverlauf: " << std::endl;
    for(int i = 0; i < event_counter + 1; i++){
        std::cout << "Runde: " << events[i].round << std::endl;
        std::cout << events[i].eventDescription << std::endl;
    }
}
