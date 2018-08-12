#include <iostream>
#include "weapon_classifier.h"
#include "weapon.h"
#include "params.h"
using namespace std;

int main() {
    IClassifier* classifier = new WeaponClassifier();
    IParams* params = new Params();
    IParams* requirements = params;
    IItem* weapon = new Weapon(*classifier, *params, *requirements);
    cout << "1" << endl;
    return 0;
}