#include "jewerly_classifier.h"


JewerlyClassifier::JewerlyClassifier() :
    IClassifier(),
    _class( EItemClass::_jewerly ),
    _type( EJewerlyType::_none ),
    _material( EJewerlyMaterial::_none )
{ }


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

