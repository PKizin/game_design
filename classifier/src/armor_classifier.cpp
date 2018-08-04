#include "armor_classifier.h"


ArmorClassifier::ArmorClassifier() : 
    IClassifier(),
    _class( EItemClass::_weapon ),
    _type( EArmorType::_none ),
    _material( EArmorMaterial::_none ) 
{ }


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

