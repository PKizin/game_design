#include <iostream>
#include "weapon_classifier.hpp"
#include "weapon_factory.hpp"
#include "weapon.hpp"
#include "armor_classifier.hpp"
#include "armor_factory.hpp"
#include "armor.hpp"
#include "randomizer.hpp"
#include "libpq-fe.h"
using namespace std;

int main() {
    /*Randomizer::init();

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
    item2.print();*/

    const char* conninfo;
    PGconn* conn;
    PGresult* res;

    conninfo = "dbname=postgres user=postgres password=1";

    conn = PQconnectdb(conninfo);

    if (PQstatus(conn) == CONNECTION_OK) {
        std::cout << std::endl;
        std::cout << "Connect to" << std::endl;
        std::cout << "host : " << PQhost(conn) << std::endl;
        std::cout << "port : " << PQport(conn) << std::endl;
        std::cout << "db   : " << PQdb(conn) << std::endl;
        std::cout << "user : " << PQuser(conn) << std::endl;
        std::cout << "pass : " << PQpass(conn) << std::endl;
    }

    PQfinish(conn);
    
    return 0;
}