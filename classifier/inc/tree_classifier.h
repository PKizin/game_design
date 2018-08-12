#ifndef TREE_CLASSIFIER_H
#define TREE_CLASSIFIER_H

#include "i_classifier.h"
#include "e_obstacle_categories.h"


class TreeClassifier : public IClassifier {
public:
    TreeClassifier();
    TreeClassifier(const TreeClassifier&);
    virtual ~TreeClassifier() { }

    int get_class() const override;
    int get_type() const override;
    void set_type(int) override;

    TreeClassifier& operator=(const TreeClassifier&);
    
private:
    EObstacleClass _class;
    ETreeType _type;
};


#endif // TREE_CLASSIFIER_H
