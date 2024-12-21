#include <iostream>

#include "Akuarium.h"
// #include "Volume.h"

Akuarium::Akuarium(float maxVolume, int currentFishCount, float currentTemp) {
    fishCount = currentFishCount;
    temp = currentTemp;
    tanki.max = maxVolume;
    tanki.current = maxVolume;
    dirtyPercen = 0;
}

int Akuarium::getFishCount() const {
    return fishCount;
}
void Akuarium::addFish(int amount) {
    fishCount += amount;
}
void Akuarium::minFish(int amount) {
    addFish(-amount);
}
void Akuarium::setFish(int value) {
    fishCount = value;
}

float Akuarium::getTemp() const {
    return temp;
}
void Akuarium::upTemp(float amount) {
    temp += amount;
}
void Akuarium::downTemp(float amount) {
    upTemp(-amount);
}
void Akuarium::setTemp(float value) {
    temp = value;
}

Volume Akuarium::getTanki() const {
    return tanki;
}
float Akuarium::tankiCapacity() {
    return getTanki().max / 100;
}
void Akuarium::addCurrentTanki(float amount) {
    tanki.current += amount;
}
void Akuarium::minCurrentTanki(float amount) {
    addCurrentTanki(-amount);
}
void Akuarium::setCurrentTanki(float value) {
    tanki.current = value;
}

float Akuarium::getDirty() const {
    return dirtyPercen;
}
void Akuarium::upDirty(float amount) {
    dirtyPercen += amount;
}
void Akuarium::downDirty(float amount) {
    upDirty(-amount);
}
void Akuarium::setDirty(float value) {
    dirtyPercen = value;
}

void Akuarium::display() {
    cout << "Akuarium" << endl
        << "Volume         : " << getTanki().current << "/" << getTanki().max << endl\
        << "Tanki Capacity : " << tankiCapacity() << endl
        << "Fish Count     : " << getFishCount() << endl
        << "Temperature    : " << getTemp() << "deg" << endl
        << "Dirty Percen   : " << getDirty() << "%" << endl;
}