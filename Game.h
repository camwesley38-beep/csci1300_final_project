#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Authority.h"

// Game controls the games main loop, player decesions and menu

class Game {
    private:
    Player player;
    Authority officer;
    bool running;
    int finalDay;

    public:
    Game();

    void start();
    void printMenu();
    void handleChoice(int choice);

    void printStatus();
    void travel();
    void riskyJob();
    void talkToAuthority();

    bool isGameOver();
    void printEnding();

};

#endif