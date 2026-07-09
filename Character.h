#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

// Character stores information for the player in a interaction
class Character {
    private:
    string name;
    string dialogue;
    int suspicionLevel;

    public:
    Character();
    Character(string characterName, string characterDialogue);

    void setName(string characterName);
    void setDialogue(string characterDialogue);
    void increaseSuspicion(int amount);
    void decreaseSuspicion(int amount);

    string getName();
    string getDialogue();
    int getSuspicionLevel();
};

#endif