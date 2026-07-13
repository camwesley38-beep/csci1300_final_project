#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Authority.h"
#include <vector>
#include "Item.h"
#include <string>
#include "Character.h"
// Game controls the games main loop, player decesions and menu

class Game {
    private:
    Player player;
    Authority officer;
    bool running;
    int finalDay;

    vector<string> locations;
    vector<Item> shopItems;
    vector<Item> inventory;
    vector<Character> civilians;

    public:
    Game();

    bool loadItems(string filename);
    void shop();
    void viewInventory();
    bool hasItem(string perkType);

    void start();
    void printMenu();
    void handleChoice(int choice);
    void viewMap();

    void printStatus();
    void travel();
    void riskyJob();
    void talkToAuthority();
    void talkToCivilian();

    bool isGameOver();
    void printEnding();
    bool loadLocations(string filename);


};

#endif