#ifndef POTION_CLASSIFIER_HPP
#define POTION_CLASSIFIER_HPP

#include "i_classifier.hpp"
#include "e_item_categories.hpp"


class PotionClassifier : public IClassifier {
public:
    PotionClassifier();
    PotionClassifier(PotionType, PotionProperty1);
    PotionClassifier(const PotionClassifier&);
    PotionClassifier(const IClassifier&);
    virtual ~PotionClassifier() { }

    int get_class() const override;
    int get_type() const override;
    int get_property1() const override;
    void set_type(int) override;
    void set_property1(int) override;

    IClassifier& operator=(const IClassifier&) override;
    PotionClassifier& operator=(const PotionClassifier&);

private:
    ItemClass _class;
    PotionType _type;
    PotionProperty1 _property1;
};


#endif // POTION_CLASSIFIER_HPP
