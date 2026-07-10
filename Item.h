#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

// Item stores one purchable object and its gameplay benifits

class Item {
    private:
    string name;
    int cost;
    string perkType;

    public:
    Item();
    Item(string itemName, int itemCost, string itemPerk);

    string getName();
    int getCost();
    string getPerkType();

};

#endif