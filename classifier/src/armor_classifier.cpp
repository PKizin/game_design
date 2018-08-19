#include "armor_classifier.h"
#include <iostream>


ArmorClassifier::ArmorClassifier() : 
    IClassifier(),
    _class( EItemClass::_weapon ),
    _type( EArmorType::_none ),
    _material( EArmorMaterial::_none ) 
{
}

ArmorClassifier::ArmorClassifier(EArmorType type, EArmorMaterial material) :
    IClassifier(),
    _class( EItemClass::_armor ),
    _type( type ),
    _material( material )
{
}

ArmorClassifier::ArmorClassifier(const ArmorClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type ),
    _material( other._material )
{
}

ArmorClassifier::ArmorClassifier(const IClassifier& other) :
    ArmorClassifier( static_cast< const ArmorClassifier& >(other) )
{
}


int ArmorClassifier::get_class() const {
    return static_cast<int>(_class);
}

int ArmorClassifier::get_type() const {
    return static_cast<int>(_type);
}

int ArmorClassifier::get_material() const {
    return static_cast<int>(_material);
}


void ArmorClassifier::set_type(int val) {
    _type = static_cast< EArmorType >(val);
}

void ArmorClassifier::set_material(int val) {
    _material = static_cast< EArmorMaterial >(val);
}


void ArmorClassifier::print() const {
    const std::string class_tags[] = { "none", "weapon", "armor", "jewerly", "potion" };
    const std::string type_tags[] = { "none", "head", "shoulders", "chest", "hands", "belt", "legs", "feet" };
    const std::string material_tags[] = { "none", "rags", "cotton", "mail", "leather" };

    std::cout << "classifier:\n";
    std::cout << "\tclass     : " << class_tags[ static_cast<int>(_class) ] << '\n';
    std::cout << "\ttype      : " << type_tags[ static_cast<int>(_type) ] << '\n';
    std::cout << "\tmaterial  : " << material_tags[ static_cast<int>(_material) ] << "\n\n";
}


IClassifier& ArmorClassifier::operator=(const IClassifier& other) {
    return operator=( static_cast< const ArmorClassifier& >(other) );
}

ArmorClassifier& ArmorClassifier::operator=(const ArmorClassifier& other) {
    _class = other._class;
    _type = other._type;
    _material = other._material;
    return *this;
}
