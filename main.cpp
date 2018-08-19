#include <iostream>
#include "weapon_classifier.h"
#include "weapon_factory.h"
#include "weapon.h"
#include "armor_classifier.h"
#include "armor_factory.h"
#include "armor.h"
#include "randomizer.h"
using namespace std;

int main() {
    Randomizer::init();

    WeaponFactory weapon_factory;
    Weapon weapon;

    ArmorFactory armor_factory;
    Armor armor;

    IFactory& factory1 = weapon_factory;
    IFactory& factory2 = armor_factory;

    IItem& item1 = weapon;
    IItem& item2 = armor;

    factory1.build_item(item1);
    factory2.build_item(item2);

    item1.print();
    item2.print();
    
    return 0;
}