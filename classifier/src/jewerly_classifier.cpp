#include "jewerly_classifier.h"


JewerlyClassifier::JewerlyClassifier() :
    IClassifier(),
    _class( ItemClass::_jewerly ),
    _type( JewerlyType::_NONE ),
    _material( JewerlyMaterial::_NONE )
{
}

JewerlyClassifier::JewerlyClassifier(const JewerlyClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type ),
    _material( other._material )
{
}


int JewerlyClassifier::get_class() const {
    return static_cast<int>(_class);
}

int JewerlyClassifier::get_type() const {
    return static_cast<int>(_type);
}

int JewerlyClassifier::get_material() const {
    return static_cast<int>(_material);
}


void JewerlyClassifier::set_type(int type) {
    _type = static_cast< JewerlyType >(type);
}

void JewerlyClassifier::set_material(int material) {
    _material = static_cast< JewerlyMaterial >(material);
}


JewerlyClassifier& JewerlyClassifier::operator=(const JewerlyClassifier& other) {
    _class = other._class;
    _type = other._type;
    _material = other._material;
    return *this;
}
