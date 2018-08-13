#include "weapon_classifier.h"
#include <iostream>


WeaponClassifier::WeaponClassifier() :
    IClassifier(),
    _class( EItemClass::_weapon ),
    _type( EWeaponType::_none ),
    _material( EWeaponMaterial::_none ),
    _property1( EWeaponProperty1::_none )
{
}

WeaponClassifier::WeaponClassifier(EWeaponType type, EWeaponMaterial material, EWeaponProperty1 property1) :
    IClassifier(),
    _class( EItemClass::_weapon ),
    _type( type ),
    _material( material ),
    _property1( property1 )
{
}

WeaponClassifier::WeaponClassifier(const WeaponClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type ),
    _material( other._material ),
    _property1( other._property1 )
{
}


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


void WeaponClassifier::print() const {
    std::cout << "This " 
        << EItemClassTags[ static_cast<int>(_class) ] << " is " 
        << EWeaponPropTags[ static_cast<int>(_property1) ] << " " 
        << EWeaponTypeTags[ static_cast<int>(_type) ] << " made by " 
        << EWeaponMatTags[ static_cast<int>(_material) ];
}


IClassifier& WeaponClassifier::operator=(const IClassifier& other) {
    return operator=( dynamic_cast< WeaponClassifier& >(const_cast< IClassifier& >(other)) );
}

WeaponClassifier& WeaponClassifier::operator=(const WeaponClassifier& other) {
    _class = other._class;
    _type = other._type;
    _material = other._material;
    _property1 = other._property1;
    return *this;
}
