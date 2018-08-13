#include <iostream>
#include "weapon_classifier.h"
#include "weapon.h"
#include "params.h"
using namespace std;

int main() {
    const IClassifier& classifier = WeaponClassifier();
    const IParams& params = Params();
    const IParams& requirements = params;
    const IItem& weapon = Weapon(classifier, params, requirements);
    const IClassifier& cla = WeaponClassifier();
    weapon.get_classifier(cla);
    cout << cla.get_class() << endl;
    return 0;
}