#include "Character.h"

Character::Character() {
    name = "Unknown";
    dialogue = "nNo dialogue available.";
    suspicionLevel = 0;
}

Character::Character(string characterName, string characterDialogue) {
    if (characterName == "") {
        name = "Unkown";
    } else {
        name = characterName;
    }

    if (characterDialogue == "") {
        dialogue = "No dialogue available";
    } else {
        dialogue = characterDialogue;
    }

    suspicionLevel = 0;
}

void Character::setName(string characterName) {
    if (characterName !="") {
        name = characterName;
    }
}

void Character::setDialogue(string characterDialogue) {
    if (characterDialogue !="") {
        dialogue = characterDialogue;
    }
}

void Character::increaseSuspicion(int amount) {
    if (amount > 0) {
        suspicionLevel += amount;
    }

    if (suspicionLevel > 100) {
        suspicionLevel = 100;
    }
}
void Character::decreaseSuspicion(int amount) {
    if (amount > 0) {
        suspicionLevel -= amount;
    }

    if (suspicionLevel < 0){
        suspicionLevel = 0;
    }
}

string Character::getName() {
    return name;
}

string Character::getDialogue() {
    return dialogue;
}

int Character::getSuspicionLevel() {
    return suspicionLevel;
}