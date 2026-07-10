#include "Item.h"

Item::Item() {
    name = "Unkown";
    cost = 0;
    perkType = "none";
}

Item::Item(string itemName, int itemCost, string itemPerk) {
    if (itemName == "") {
        name = "Unknown";
    } else {
        name = itemName;
    }

    if(itemCost < 0) {
        cost = 0;
    } else {
        cost = itemCost;
    }

    if(itemPerk == "") {
        perkType = "none";
    } else {
        perkType = itemPerk;
    }

}

string Item::getName() {
    return name;
}

int Item::getCost() {
    return cost;
}

string Item::getPerkType() {
    return perkType;
}