#include "tree_classifier.h"


TreeClassifier::TreeClassifier() :
    IClassifier(),
    _class( EObstacleClass::_tree ),
    _type( ETreeType::_none )
{
}

TreeClassifier::TreeClassifier(const TreeClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type )
{
}


int TreeClassifier::get_class() const {
    return static_cast<int>(_class);
}

int TreeClassifier::get_type() const {
    return static_cast<int>(_type);
}


void TreeClassifier::set_type(int type) {
    _type = static_cast< ETreeType >(type);
}


TreeClassifier& TreeClassifier::operator=(const TreeClassifier& other) {
    _class = other._class;
    _type = other._type;
    return *this;
}
