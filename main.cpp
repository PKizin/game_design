#include <iostream>
#include <functional>
#include "weapon_classifier.hpp"
#include "weapon_factory.hpp"
#include "weapon.hpp"
#include "armor_classifier.hpp"
#include "armor_factory.hpp"
#include "armor.hpp"
#include "potion_classifier.hpp"
#include "potion_factory.hpp"
#include "potion.hpp"
#include "randomizer.hpp"
#include "pg_tester.hpp"
#include "i_action.hpp"
#include "e_body_containers.hpp"
using namespace std;

int main() {
    Randomizer::init();

    const IFactory& factory1 = WeaponFactory();
    const IFactory& factory2 = ArmorFactory();
    const IFactory& factory3 = PotionFactory();

    Weapon weapon;
    Armor armor;
    Potion potion;

    IItem& item1 = weapon;
    IItem& item2 = armor;
    IItem& item3 = potion;

    factory1.build_item(item1);
    factory2.build_item(item2);
    factory3.build_item(item3);

    item1.print();
    item2.print();
    item3.print();


    //PGtester tester("postgres_win1252", "postgres", "1");
    //tester.test();
    
    return 0;
}