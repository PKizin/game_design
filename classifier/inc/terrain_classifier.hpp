#ifndef TERRAIN_CLASSIFIER_H
#define TERRAIN_CLASSIFIER_H

#include "i_classifier.hpp"
#include "e_obstacle_categories.hpp"


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
    ObstacleClass _class;
    TerrainType _type;
};


#endif // TERRAIN_CLASSIFIER_H
