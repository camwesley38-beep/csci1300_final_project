#include "PLAYER.h"

// Default numbers the player is given at the start
Player::Player() {
    money = 0;
    risk = 0;
    experience = 0;
    day = 1;
    location = "Downtown";

}
// adds money if the money earned is positive
void Player::earnMoney(int amount) {
    if (amount > 0) {
        money += amount;
    
    }
}
// sees if the player can purchase it if so subracts the cost from money
bool Player::spendMoney(int amount) {
    if (amount < 0) {
        return false;
    }

    if (amount > money) {
        return false;
    }

    money -= amount;
    return true;
}
// increases risk if it was risk above 0 and the amount of risk the action had
void Player::increaseRisk(int amount) {
    if (amount > 0) {
        risk -= amount;
    }

    if (risk < 0) {
        risk = 0;
    }
}

void Player::decreaseRisk(int amount) {
    if (amount > 0) {
        risk -= amount;
    }

    if (risk < 0) {
        risk = 0;
    }
}

void Player::addExperience(int amount) {
    if (amount > 0) {
        experience += amount;
    }
}

void Player::nextDay() {
    day++;
}

void Player::moveLocation(string newLocation) {
    if (newLocation !="") {
        location = newLocation;
    }
}

int Player::getMoney() {
    return money;
}

int Player::getRisk() {
    return risk;
}

int Player::getExperience() {
    return experience;
}

int Player::getDay() {
    return day;
}

string Player::getLocation() {
    return location;
}