#include "terrain_classifier.h"


TerrainClassifier::TerrainClassifier() :
    IClassifier(),
    _class( EObstacleClass::_terrain ),
    _type( ETerrainType::_none )
{ }


int TerrainClassifier::get_class() const {
    return static_cast<int>(_class);
}

int TerrainClassifier::get_type() const {
    return static_cast<int>(_type);
}


void TerrainClassifier::set_type(int type) {
    _type = static_cast< ETerrainType >(type);
}

