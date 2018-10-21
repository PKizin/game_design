#include <iostream>
#include "weapon_classifier.hpp"
#include "weapon_factory.hpp"
#include "weapon.hpp"
#include "armor_classifier.hpp"
#include "armor_factory.hpp"
#include "armor.hpp"
#include "randomizer.hpp"
#include "pg_tester.hpp"
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

    //PGtester tester("postgres_win1252", "postgres", "1");
    //tester.test();
    
    return 0;
}