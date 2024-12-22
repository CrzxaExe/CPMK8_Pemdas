#ifndef AKUARIUM_H
#define AKUARIUM_H

#include <iostream>
#include <list>
#include <iterator>
#include "Custom_Struct.h"

using namespace std;

class Akuarium {
    // Properti akuarium
    private:
        list<Fish> fishs = {};
        float temp;
        Volume tanki;
        float dirtyPercen;

    public:
        Akuarium(float maxVolume, float currentTemp);

        // Fungsi untuk ikan
        int getFishCount() const;
        int getTotalFishCount () const;
        string stringFish();
        list<Fish>::iterator getFish(string fishType);
        void addFish(string fishType, int amount);
        void minFish(string fishType, int amount);
        void setFish(string fishType, int value);

        // Fungsi temperatur
        float getTemp() const;
        void upTemp(float amount);
        void downTemp(float amount);
        void setTemp(float value);

        // Fungsi tanki
        Volume getTanki() const;
        float tankiCapacity();
        void addCurrentTanki(float amount);
        void minCurrentTanki(float amount);
        void setCurrentTanki(float value);

        // Fungsi persentase kotor
        float getDirty() const;
        void upDirty(float amount);
        void downDirty(float amount);
        void setDirty(float value);

        // Fungsi lain
        void display();
        string isFishStress();
        string solution();
};

#endif // !AKUARIUM_H