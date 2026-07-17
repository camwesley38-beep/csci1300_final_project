#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

Game::Game() {
    officer = Authority("Investigator", "I am watching the city closely.", 20);
    running = true;
    finalDay = 7;

    if (!loadItems("item.txt")) {
        shopItems.push_back(Item("FakeID", 75, "fakeid"));
        shopItems.push_back(Item("OldPhone", 50, "phone"));
        shopItems.push_back(Item("Crowbar",100, "crowbar"));
        shopItems.push_back(Item("GasCan", 80, "gascan"));
        shopItems.push_back(Item("Backpack", 60, "backpack"));
    }

    if (!loadLocations("locations.txt")) {
        locations.push_back("downtown");
        locations.push_back("Warehouse District");
        locations.push_back("suburbs");
    }
    // civilians givethe player different story clues and gameplay effects.
    civilians.push_back(Character("Store Clerk", "I heard about about a security increase at the warehouse recently, i wonder why"));
    civilians.push_back(Character("Family Member", "I've heard people talking about you recently. Lay low."));
    civilians.push_back(Character("Paraniod civilian", "I havent see you around much what are you doing"));
    civilians.push_back(Character("Old Freind","Ive heard some rumours i could calm it down for you"));    
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
    cout << "6. Buy item" << endl;
    cout << "7. View inventory" << endl;
    cout << "8. View map" << endl;
    cout << "9. Talk to civilian" << endl;
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
    } else  if (choice == 6) {
        shop();
    } else if (choice == 7) {
        viewInventory();
    } else if (choice == 8) {
        viewMap();
    } else if (choice == 9) {
        talkToCivilian();
    } else {
        cout << "Invalid option." << endl;
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

    int moneyEarned = 150;
    int riskAdded = 20;
    int pressureAdded = 10;

    if (hasItem("crowbar")) {
        moneyEarned += 75;
        riskAdded += 10;
        cout << "Crowbar perk: you earned more, but suspicion rose faster." << endl;
    }

    if (hasItem("backpack")) {
        moneyEarned += 75;
        riskAdded += 10;
        cout << "Crowbar perk: You earned more, but suspicion rose faster." << endl;
    }

    if(hasItem("backpack")) {
        moneyEarned += 50;
        riskAdded += 5;
        cout << "Backpack perk: You carried more, but looked more suspicious." << endl;
    }

    if (hasItem("fakeid")) {
        riskAdded -= 10;
        cout << "FakeID perk: Suspicion from witnesses was reduced." << endl;
    }

    if (riskAdded < 0) {
        riskAdded = 0;
    }

    player.earnMoney(moneyEarned);
    player.increaseRisk(riskAdded);
    player.addExperience(5);
    officer.increasePressure(pressureAdded);
    player.nextDay();

    cout << "You earned $" << moneyEarned << "." << endl;
    cout << "Your risk increased by " << riskAdded << "." << endl;
}

void Game::talkToAuthority() {
    cout << endl;
    cout << officer.getName() << ": " << officer.getDialogue() << endl;
    cout << "You try to calm things down." << endl;

    if (hasItem("gascan")) {
        officer.decreasePressure(15);
        cout << "GasCan perk: Authority pressure cooled down." << endl;
    }

    if (hasItem("phone")) {
        cout << "OldPhone perk: get information on risky areas before moving. " << endl;
    }

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

bool Game::loadItems(string filename) {
    ifstream fileIn;
    fileIn.open(filename);

    if (!fileIn.is_open()) {
        return false;
    }

    shopItems.clear();

    string name;
    int cost;
    string perkType;

    while (fileIn >> name >> cost >> perkType) {
        Item item(name, cost, perkType);
        shopItems.push_back(item);
    }

    fileIn.close();

    return shopItems.size() > 0;
}

bool Game::hasItem(string perkType) {
    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        if (inventory[i].getPerkType() == perkType) {
            return true;
        }
    }

    return false;
}

void Game::viewInventory() {
    cout << endl;
    cout << "--- Inventory ---" << endl;

    if (inventory.size() == 0) {
        cout << "You do not have any items." << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(inventory.size()); i++) {
        cout << i + 1 << "." << inventory[i].getName()
        << " - perk: " << inventory[i].getPerkType() << endl;

    }
}

void Game::viewMap() {
    cout << endl;
    cout << "--- City Map ---" << endl;

    if (locations.size() == 0) {
        cout << "No locations are currently loaded." << endl;
        return;
    }

    for (int i = 0; i < static_cast<int>(locations.size()); i++) {
        cout << i + 1 << locations[i];

        if (locations[i] == player.getLocation()) {
            cout << "  <-- You are here";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Travel paths:" << endl;

    for(int i = 0; i < static_cast<int>(locations.size()) - 1; i++) {
        cout << locations[i] << " -> " << locations[i + 1] << endl;
    }
} 

void Game::shop() {
    cout << endl;
    cout << "--- Black Market Shop ---" << endl;

    for (int i = 0; i < static_cast<int>(shopItems.size()); i++) {
        cout << i + 1 << "." << shopItems[i].getName()
        << " - $" << shopItems[i].getCost()
        << " - perk: " << shopItems[i].getPerkType() << endl;
    }

    cout << "Choose an item to buy, or 0 to leave: ";

    int choice;
    cin >> choice;

    if (choice == 0) {
        return;
    }

    if (choice < 1 || choice > static_cast<int>(shopItems.size())) {
        cout << "Invalid item." << endl;
        return;
    }

    Item selectedItem = shopItems[choice - 1];

    if (player.spendMoney(selectedItem.getCost())) {
        inventory.push_back(selectedItem);
        cout << "You bought " << selectedItem.getName() << "." << endl;

    } else {
        cout << "You do not have enough money." << endl;
    }
}

// Each characters gives a differnt effect so characters matter in gameplay.
// Lets players talk to civilians.
void Game::talkToCivilian() {
    cout << endl;
    cout << "--- Civilians ---" << endl;

    for (int i = 0; i < static_cast<int>(civilians.size()); i++) {
        cout << i + 1 << ". " << civilians[i].getName() << endl;
    }
    
    cout << "Choose someone to talk to; or 0 to leave:";
    
    int choice;
    cin >> choice;

    if (choice == 0) {
        return;
    }

    if (choice < 1 || choice > static_cast<int>(civilians.size())) {
        cout << "Invalid civilian." << endl;
        return;
    }

    Character selectedCivilian = civilians[choice - 1];

    cout << endl;
    cout << selectedCivilian.getName() << ":" 
        << selectedCivilian.getDialogue() << endl;

    if (choice == 1) {
        cout << "The clerk gives you warning about risky locations." << endl;
        player.addExperience(3);
    } else if (choice == 2) {
        cout << "This family member helps lower your risk." << endl;
        player.decreaseRisk(10);
    } else if (choice == 3) {
        cout << "This paraniod civilian spreads rumours increasing suspicion." << endl;

        if(hasItem("fakeid")) {
            cout << "FakeID perk: The rumour is spread on your fake identy not you" << endl;


        } else {
            player.increaseRisk(10);
            officer.increasePressure(5);

        }
    } else if (choice == 4) {
        cout << "Your old friend helps calm things down." << endl;
        player.decreaseRisk(5);
        officer.decreasePressure(5);
    }

    player.nextDay();
}
