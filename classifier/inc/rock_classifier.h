#ifndef ROCK_CLASSIFIER_H
#define ROCK_CLASSIFIER_H

#include "i_classifier.h"
#include "e_obstacle_categories.h"


class RockClassifier : public IClassifier {
public:
    RockClassifier();
    virtual ~RockClassifier() { }

    int get_class() const override;
    int get_type() const override;
    void set_type(int) override;

private:
    RockClassifier(const RockClassifier&);
    RockClassifier& operator=(const RockClassifier&);

    EObstacleClass _class;
    ERockType _type;
};


#endif // ROCK_CLASSIFIER_H
