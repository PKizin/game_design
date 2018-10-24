#ifndef TREE_CLASSIFIER_HPP
#define TREE_CLASSIFIER_HPP

#include "i_classifier.hpp"
#include "e_obstacle_categories.hpp"


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
    ObstacleClass _class;
    TreeType _type;
};


#endif // TREE_CLASSIFIER_HPP
