#ifndef GEGNER_H_INCLUDED
#define GEGNER_H_INCLUDED

class Gegner{
    public:
        Gegner();
        void enemyMove();
        void enemyDamage();
        void enemyHeal(int level);
        int get_x();
        int get_y();
        int get_lives();
        int get_fight();
        int fightSimulator();

    private:
        int Lebenspunkte;
        int x;
        int y;
        int enemy_move;
        int fight;
};

#endif // GEGNER_H_INCLUDED
