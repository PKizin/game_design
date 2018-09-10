#include "armor_classifier.h"
#include <iostream>


ArmorClassifier::ArmorClassifier() : 
    IClassifier(),
    _class( ItemClass::_weapon ),
    _type( ArmorType::_NONE ),
    _material( ArmorMaterial::_NONE ) 
{
}

ArmorClassifier::ArmorClassifier(ArmorType type, ArmorMaterial material) :
    IClassifier(),
    _class( ItemClass::_armor ),
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
    _type = static_cast< ArmorType >(val);
}

void ArmorClassifier::set_material(int val) {
    _material = static_cast< ArmorMaterial >(val);
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
