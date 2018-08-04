#ifndef POTION_CLASSIFIER_H
#define POTION_CLASSIFIER_H

#include "i_classifier.h"
#include "e_item_categories.h"


class PotionClassifier : public IClassifier {
public:
    PotionClassifier();
    virtual ~PotionClassifier() { }

    int get_class() const override;
    int get_type() const override;
    int get_property1() const override;
    void set_type(int) override;
    void set_property1(int) override;

private:
    PotionClassifier(const PotionClassifier&);
    PotionClassifier& operator=(const PotionClassifier&);

    EItemClass _class;
    EPotionType _type;
    EPotionProperty1 _property1;
};


#endif // POTION_CLASSIFIER_H
