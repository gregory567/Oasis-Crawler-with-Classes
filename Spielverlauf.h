#ifndef SPIELVERLAUF_H_INCLUDED
#define SPIELVERLAUF_H_INCLUDED


class Spielverlauf{
    public:
        Spielverlauf();
        void increaseRound();
        int get_round_counter();
        void level_up();
        int get_level();
        void createStat(const char* highlight);
        void printStats();

    private:
        struct Event{
            int round;
            const char* eventDescription;
        };
        struct Event events[100];
        int round_counter;
        int event_counter;
        int level;
};


#endif // SPIELVERLAUF_H_INCLUDED
