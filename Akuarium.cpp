#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

#include "Akuarium.h"
#include "Custom_Struct.h"

Akuarium::Akuarium(float maxVolume, int currentFishCount, float currentTemp) {
    temp = currentTemp;
    tanki.max = maxVolume;
    tanki.current = maxVolume;
    dirtyPercen = 0;
}

int Akuarium::getFishCount() const {
    int count = 0;

    for(const Fish f : fishs) {
        count += f.count;
    }
    return count;
}
string Akuarium::stringFish() {
    string res;
    for(const Fish f : fishs) {
        res.append("\n- " + f.type + ": " + to_string(f.count));
    }
    return res;
}
list<Fish>::iterator Akuarium::getFish(string fishType) {
    list<Fish>::iterator it = find_if(fishs.begin(), fishs.end(), [&fishType](const Fish& fish) {
        return fish.type == fishType;
    });
    return it;
}
void Akuarium::addFish(string fishType, int amount) {
    list<Fish>::iterator it = getFish(fishType);
    if(it != fishs.end()) {
        it->count += amount;
    } else {
        fishs.push_back({ type: fishType, count: amount });
    }
}
void Akuarium::minFish(string fishType, int amount) {
    list<Fish>::iterator it = getFish(fishType);

    if(it == fishs.end()) return;

    if(it->count <= amount) {
        fishs.erase(it);
    } else {
        it->count -= amount;
    }
}
void Akuarium::setFish(string fishType, int value) {
    list<Fish>::iterator it = getFish(fishType);

    if(it != fishs.end()) {
        addFish(fishType, value);
    } else {
        it->count = value;
    }
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
    return getTanki().max * 1000;
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
        << "Tanki Capacity : " << tankiCapacity() << "L" << endl
        << "Fish Count     : " << getFishCount() << endl
        << "Fish Detail    : " << stringFish() << endl
        << "Temperature    : " << getTemp() << "deg" << endl
        << "Dirty Percen   : " << getDirty() << "%" << endl << endl;
}