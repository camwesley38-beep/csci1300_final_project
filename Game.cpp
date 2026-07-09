#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

Game::Game() {
    officer = Authority("Investigator", "I am watching the city closely.", 20);
    running = true;
    finalDay = 7;

    if (!loadLocations("locations.txt")) {
        locations.push_back("downtown");
        locations.push_back("Warehouse District");
        locations.push_back("suburbs");
    }
}

bool Game::loadLocations(string filename) {
    ifstream fileIn;
    fileIn.open(filename);

    if (!fileIn.is_open()) {
        return false;
    }

    locations.clear();

    string locationName;

    while (getline(fileIn, locationName)) {
        if (locationName !="") {
            locations.push_back(locationName);
        }
    }

    fileIn.close();

    return locations.size() > 0;
}

// Main game loop for the checkpoint.

void Game::start() {
    cout << "=== Risk City Simulator ===" << endl;

    while (running && !isGameOver()) {
        printMenu();

        int choice;
        cin >> choice;

        handleChoice(choice);


    }
    printEnding();
}

void Game::printMenu() {
    cout << "--- Main Menu ---" << endl;
    cout << "1. View status" << endl;
    cout << "2. Travel to new location" << endl;
    cout << "3.Take a risky job" << endl;
    cout << "4. Talk to authority" << endl;
    cout << "5. Quit" << endl;
    cout << "choose an option: ";

}

void Game::handleChoice(int choice) {
    if (choice == 1) {
        printStatus();
    } else if (choice == 2) {
        travel();
    } else if (choice == 3) {
        riskyJob();
    } else if (choice == 4) {
        talkToAuthority();
    } else if (choice == 5) {
        running = false;
    } else {
        cout << "Invalid choice." << endl;
    }
}

void Game::printStatus() {
    cout << endl;
    cout << "--- Player Status ---" << endl;
    cout << "Day: " << player.getDay() << endl;
    cout << "Location: " << player.getLocation() << endl;
    cout << "Money: $" << player.getMoney() << endl;
    cout << "Risk: " << player.getRisk() << endl;
    cout << "Experience: " << player.getExperience() << endl;
    cout << "Authority Pressure: " << officer.getPressureLevel() << endl;
}

void Game::travel() {
    int choice;

    cout << endl;
    cout <<"--- Locations ---" << endl;
    
    for (int i = 0; i < static_cast<int>(locations.size()); i++) {
        cout << i + 1 << "." << locations[i] << endl;
    }

    cout << "Choose location: ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(locations.size())) {
        cout << "Invalid location." << endl;
        return;
    }

    player.moveLocation(locations[choice - 1]);
    player.nextDay();

    cout << "You moved to " << player.getLocation() << "." << endl;

}

void Game::riskyJob() {
    cout << endl;
    cout << "You chose a risky shortcut to earn money." << endl;
}

void Game::talkToAuthority() {
    cout << endl;
    cout << officer.getName() << ": " << officer.getDialogue() << endl;
    cout << "You try to calm things down." << endl;

    player.decreaseRisk(10);
    officer.decreasePressure(10);
    player.nextDay();
}

bool Game::isGameOver() {
    if (player.getRisk() >= 100) {
        return true;
    }

    if (player.getDay() > finalDay) {
        return true;
    }

    return false;
}

void Game::printEnding() {
    cout << endl;
    cout << "--- Game Over ---" << endl;

    if (player.getRisk() >= 100) {
        cout << "Your risk got too high, and your wanted by the police." << endl;
    } else if (player.getMoney() >= 1000) {
        cout << "Your rich and never have to work again" << endl;
    } else {
        cout << "Your too old and broke, lifes gonna be tough." << endl;
    }
}