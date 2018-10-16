#ifndef ROCK_CLASSIFIER_H
#define ROCK_CLASSIFIER_H

#include "i_classifier.hpp"
#include "e_obstacle_categories.hpp"


class RockClassifier : public IClassifier {
public:
    RockClassifier();
    RockClassifier(const RockClassifier&);
    virtual ~RockClassifier() { }

    int get_class() const override;
    int get_type() const override;
    void set_type(int) override;

    RockClassifier& operator=(const RockClassifier&);

private:
    ObstacleClass _class;
    RockType _type;
};


#endif // ROCK_CLASSIFIER_H
