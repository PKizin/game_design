#include "potion_classifier.h"


PotionClassifier::PotionClassifier() :
    IClassifier(),
    _class( EItemClass::_potion ),
    _type( EPotionType::_none ),
    _property1( EPotionProperty1::_none )
{ }


int PotionClassifier::get_class() const {
    return static_cast<int>(_class);
}

int PotionClassifier::get_type() const {
    return static_cast<int>(_type);
}

int PotionClassifier::get_property1() const {
    return static_cast<int>(_property1);
}


void PotionClassifier::set_type(int type) {
    _type = static_cast< EPotionType >(type);
}

void PotionClassifier::set_property1(int property1) {
    _property1 = static_cast< EPotionProperty1 >(property1);
}
