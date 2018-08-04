#include "weapon_classifier.h"


WeaponClassifier::WeaponClassifier() :
    IClassifier(),
    _class( EItemClass::_weapon ),
    _type( EWeaponType::_none ),
    _material( EWeaponMaterial::_none ),
    _property1( EWeaponProperty1::_none )
{ }


int WeaponClassifier::get_class() const {
    return static_cast<int>(_class);
}

int WeaponClassifier::get_type() const {
    return static_cast<int>(_type);
}

int WeaponClassifier::get_material() const {
    return static_cast<int>(_material);
}

int WeaponClassifier::get_property1() const {
    return static_cast<int>(_property1);
}


void WeaponClassifier::set_type(int type) {
    _type = static_cast< EWeaponType >(type);
}

void WeaponClassifier::set_material(int material) {
    _material = static_cast< EWeaponMaterial >(material);
}

void WeaponClassifier::set_property1(int property1) {
    _property1 = static_cast< EWeaponProperty1 >(property1);
}

