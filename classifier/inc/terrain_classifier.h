#ifndef TERRAIN_CLASSIFIER_H
#define TERRAIN_CLASSIFIER_H

#include "i_classifier.h"
#include "e_obstacle_categories.h"


class TerrainClassifier : public IClassifier {
public:
    TerrainClassifier();
    TerrainClassifier(const TerrainClassifier&);
    virtual ~TerrainClassifier() { }

    int get_class() const override;
    int get_type() const override;
    void set_type(int) override;

    TerrainClassifier& operator=(const TerrainClassifier&);

private:
    EObstacleClass _class;
    ETerrainType _type;
};


#endif // TERRAIN_CLASSIFIER_H
