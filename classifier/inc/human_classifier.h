#ifndef HUMAN_CLASSIFIER_H
#define HUMAN_CLASSIFIER_H

#include "i_classifier.h"
#include "e_creature_categories.h"


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


#endif // HUMAN_CLASSIFIER_H
