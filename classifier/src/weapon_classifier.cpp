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

WeaponClassifier::WeaponClassifier(const IClassifier& other) :
    WeaponClassifier( static_cast< const WeaponClassifier& >(other) )
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
    const std::string class_tags[] = { "none", "weapon", "armor", "jewerly", "potion" };
    const std::string type_tags[] = { "none", "stick", "dagger", "sword", "staff" };
    const std::string material_tags[] = { "none", "wood", "steel", "glass" };
    const std::string property1_tags[] = { "none", "one-handed", "two-handed" };

    std::cout << "classifier:\n";
    std::cout << "\tclass     : " << class_tags[ static_cast<int>(_class) ] << '\n';
    std::cout << "\ttype      : " << type_tags[ static_cast<int>(_type) ] << '\n';
    std::cout << "\tmaterial  : " << material_tags[ static_cast<int>(_material) ] << '\n';
    std::cout << "\tproperty1 : " << property1_tags[ static_cast<int>(_property1) ] << "\n\n";
}


IClassifier& WeaponClassifier::operator=(const IClassifier& other) {
    return operator=( static_cast< const WeaponClassifier& >(other) );
}

WeaponClassifier& WeaponClassifier::operator=(const WeaponClassifier& other) {
    _class = other._class;
    _type = other._type;
    _material = other._material;
    _property1 = other._property1;
    return *this;
}
