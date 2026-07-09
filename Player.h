#ifndef PLAYER_H
#define PLAYER_H



#include <string>

using namespace std;

// stores the states for the player
class Player {
    private:
    int money;
    int risk;
    int experience;
    int day;
    string location;


    public:
    Player();

    void earnMoney(int amount);
    bool spendMoney(int amount);

    void increaseRisk(int amount);
    void decreaseRisk(int amount);

    void addExperience(int amount);
    void nextDay();
    void moveLocation(string newLocation);

    int getMoney();
    int getRisk();
    int getExperience();
    int getDay();
    string getLocation();

};

#endif