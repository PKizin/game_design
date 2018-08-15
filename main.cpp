#include <iostream>
#include "weapon_classifier.h"
#include "weapon_factory.h"
#include "weapon.h"
#include "params.h"
using namespace std;

int main() {
    WeaponClassifier cla(EWeaponType::_staff, EWeaponMaterial::_wood, EWeaponProperty1::_two_handed);
    Params par;
    Params req(par);

    IClassifier& ref_cla = cla;
    IParams& ref_par = par;
    IParams& ref_req = req;

    Weapon wep(ref_cla, ref_par, ref_req);
    IItem& ref_wep = wep;

    WeaponClassifier cla1;
    IClassifier& ref_cla1 = cla1;
    ref_wep.get_classifier(ref_cla1);
    ref_cla1.print();

    ref_cla.set_type( static_cast<int>(EWeaponType::_sword) );
    ref_cla.set_material( static_cast<int>(EWeaponMaterial::_steel) );
    ref_cla.set_property1( static_cast<int>(EWeaponProperty1::_one_handed) );
    ref_wep.set_classifier( ref_cla );
    ref_wep.get_classifier( ref_cla1 );
    ref_cla1.print();
    
    return 0;
}