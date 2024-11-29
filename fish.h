#ifndef FISH_H
#define FISH_H

#include <glut.h>
#include <cmath>
#include <ctime>

class fish {
public:
    int randFish(bool inAreaA) {
        srand(time(0));
        int fish = 1;

        do { fish = (rand() % 10) + 1; }
        while (fish < 2 && fish >= 4);

        switch (fish) {
        case 1:
            if (inAreaA) return 4;
            else return 14;
            break;

        case 2:
            if (inAreaA) return 5;
            else return 15;
            break;

        case 3:
            if (inAreaA) return 6;
            else return 16;
            break;

        case 4:
            if (inAreaA) return 8;
            else return 18;
            break;

        case 5:
            if (inAreaA) return 3;
            else return 13;
            break;

        case 6:
            if (inAreaA) return 10;
            else return 20;
            break;

        case 7:
            if (inAreaA) return 7;
            else return 17;
            break;

        case 8:
            if (inAreaA) return 1;
            else return 11;
            break;

        case 9:
            if (inAreaA) return 2;
            else return 12;
            break;

        case 10:
            if (inAreaA) return 9;
            else return 19;
            break;
        }
    }

    void bangus(float scale, float x, float y);
    void betta(float scale, float x, float y);
    void carp(float scale, float x, float y);
    void catfish(float scale, float x, float y);
    void goldfish(float scale, float x, float y);
    void AUfish(float scale, float x, float y);
    void janitorFish(float scale, float x, float y);
    void koi(float scale, float x, float y);
    void tilapia(float scale, float x, float y);
    void trout(float scale, float x, float y);
    void anchovy(float scale, float x, float y);
    void bass(float scale, float x, float y);
    void clownfish(float scale, float x, float y);
    void cod(float scale, float x, float y);
    void mackarel(float scale, float x, float y);
    void oarfish(float scale, float x, float y);
    void pufferfish(float scale, float x, float y);
    void sacabambaspis(float scale, float x, float y);
    void shark(float scale, float x, float y);
    void tuna(float scale, float x, float y);
};

#endif