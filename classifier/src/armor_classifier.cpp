#include "armor_classifier.h"


ArmorClassifier::ArmorClassifier() : 
    IClassifier(),
    _class( EItemClass::_weapon ),
    _type( EArmorType::_none ),
    _material( EArmorMaterial::_none ) 
{
}

ArmorClassifier::ArmorClassifier(const ArmorClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type ),
    _material( other._material )
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


ArmorClassifier& ArmorClassifier::operator=(const ArmorClassifier& other) {
    _class = other._class;
    _type = other._type;
    _material = other._material;
    return *this;
}
