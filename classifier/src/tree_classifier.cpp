#include "tree_classifier.hpp"


TreeClassifier::TreeClassifier() :
    IClassifier(),
    _class( ObstacleClass::_tree ),
    _type( TreeType::_NONE )
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
    _type = static_cast< TreeType >(type);
}


TreeClassifier& TreeClassifier::operator=(const TreeClassifier& other) {
    _class = other._class;
    _type = other._type;
    return *this;
}
