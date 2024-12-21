#ifndef AKUARIUM_H
#define AKUARIUM_H

#include <iostream>
#include "Volume.h"

using namespace std;

class Akuarium {
    // Properti akuarium
    private:
        int fishCount;
        float temp;
        Volume tanki;
        float dirtyPercen;

    public:
        Akuarium(float maxVolume, int currentFishCount, float currentTemp);

        // Fungsi untuk ikan
        int getFishCount() const;
        void addFish(int amount);
        void minFish(int amount);
        void setFish(int value);

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
        float getFishStressCount();
        void display();
};

#endif // !AKUARIUM_H