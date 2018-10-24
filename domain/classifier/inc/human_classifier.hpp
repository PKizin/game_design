#ifndef HUMAN_CLASSIFIER_HPP
#define HUMAN_CLASSIFIER_HPP

#include "i_classifier.hpp"
#include "e_creature_categories.hpp"


class HumanClassifier : public IClassifier  {
public:
    HumanClassifier();
    HumanClassifier(const HumanClassifier&);
    virtual ~HumanClassifier() { };

    int get_class() const override;
    int get_type() const override;
    void set_type(int) override;

    HumanClassifier& operator=(const HumanClassifier&);

private:
    CreatureClass _class;
    HumanType _type;
};


#endif // HUMAN_CLASSIFIER_HPP
