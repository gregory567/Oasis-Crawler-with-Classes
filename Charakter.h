#ifndef CHARAKTER_H_INCLUDED
#define CHARAKTER_H_INCLUDED

class Charakter{
    public:
        Charakter();
        void printHero();
        int playerMove();
        void playerDamage();
        void playerHeal();
        int get_x();
        int get_y();
        int get_lives();
        int dangerSimulator();
        void increaseRelicpoints();
        int get_item();

    private:
        int Lebenspunkte;
        int Reliktpunkte;
        int x;
        int y;
        int Staerke;
        int Schnelligkeit;
        int Klugheit;
        int Fitness;
        int RedBull;
        int Buch;
        char player_move;
        int false_command;
        int prob_danger;
        int dangerType;
        int damage;
        int prob_item;
        int itemType;
};

#endif // CHARAKTER_H_INCLUDED
