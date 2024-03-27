#ifndef SPIELWELT_H_INCLUDED
#define SPIELWELT_H_INCLUDED

class Spielwelt{
    public:
        Spielwelt();
        void printField(int level);
        int countHiddenRelics();
        int get_tile(int x, int y);
        void set_tile_empty(int x, int y);
        void regenerateField();

    private:
        int low;
        int high;
        int twod_world[5][5];
        int relic_counter;
        int i;
        int j;
};

#endif // SPIELWELT_H_INCLUDED
