#include <iostream>

#include "Akuarium.h"
#include "Custom_Struct.h"

using namespace std;

int main() {
    Akuarium akuarium1(4.0, 5, 34.5);

    for(int i = 0; i<3; i++) {
        akuarium1.addFish("Nila", 20);
        akuarium1.addFish("Yoga", 4);

        akuarium1.display();
        akuarium1.upDirty(rand() % 3);
        akuarium1.minCurrentTanki(rand() % 2);
        akuarium1.setTemp(rand() % 30);
    }

    return 0;
}