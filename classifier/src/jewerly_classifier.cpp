#include "jewerly_classifier.h"


JewerlyClassifier::JewerlyClassifier() :
    IClassifier(),
    _class( EItemClass::_jewerly ),
    _type( EJewerlyType::_none ),
    _material( EJewerlyMaterial::_none )
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
    _type = static_cast< EJewerlyType >(type);
}

void JewerlyClassifier::set_material(int material) {
    _material = static_cast< EJewerlyMaterial >(material);
}


JewerlyClassifier& JewerlyClassifier::operator=(const JewerlyClassifier& other) {
    _class = other._class;
    _type = other._type;
    _material = other._material;
    return *this;
}
