#ifndef AUTHORITY_H
#define AUTHORITY_H

#include "Character.h"

// Authority inherits stats from Character and when raised adds pressure and investigation events that coud lead to arrests
class Authority : public Character {
    private:
    int pressureLevel;

    public:
    Authority();
    Authority(string authorityName, string authorityDialogue, int startingPressure);

    void increasePressure(int amount);
    void decreasePressure(int amount);
    bool shouldInvestigate();

    int getPressureLevel();
};

#endif