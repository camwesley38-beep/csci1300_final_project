#include "Authority.h"

Authority::Authority() : Character() {
    pressureLevel = 0;
}

Authority::Authority(string authorityName, string authorityDialogue, int startingPressure)
   : Character(authorityName, authorityDialogue) {

    if (startingPressure < 0) {
        pressureLevel = 0;

    } else if (startingPressure > 100) {
        pressureLevel = 100;
    } else {
        pressureLevel = startingPressure;
    }
}

void Authority::increasePressure(int amount) {
    if (amount > 0) {
        pressureLevel += amount;
    }

    if (pressureLevel > 100) {
        pressureLevel = 100;
    }
}

void Authority::decreasePressure(int amount) {
    if (amount > 0) {
        pressureLevel -= amount;
    }

    if (pressureLevel < 0) {
        pressureLevel = 0;
    }
}

bool Authority::shouldInvestigate() {
    return pressureLevel >= 70;
}

int Authority::getPressureLevel() {
    return pressureLevel;
}