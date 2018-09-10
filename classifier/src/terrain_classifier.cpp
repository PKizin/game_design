#include "terrain_classifier.h"


TerrainClassifier::TerrainClassifier() :
    IClassifier(),
    _class( ObstacleClass::_terrain ),
    _type( TerrainType::_NONE )
{
}

TerrainClassifier::TerrainClassifier(const TerrainClassifier& other) :
    IClassifier( other ),
    _class( other._class ),
    _type( other._type )
{
}


int TerrainClassifier::get_class() const {
    return static_cast<int>(_class);
}

int TerrainClassifier::get_type() const {
    return static_cast<int>(_type);
}


void TerrainClassifier::set_type(int type) {
    _type = static_cast< TerrainType >(type);
}


TerrainClassifier& TerrainClassifier::operator=(const TerrainClassifier& other) {
    _class = other._class;
    _type = other._type;
    return *this;
}
