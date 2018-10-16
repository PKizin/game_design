#ifndef POTION_H
#define POTION_H

#include "i_item.h"
#include "potion_classifier.h"
#include "params.h"


class Potion : public IItem {
public:
    Potion();
    Potion(const IClassifier&, const IParams&, const IParams&);
    virtual ~Potion() { }

    void get_classifier(IClassifier&) const override;
    void get_params(IParams&) const override;
    void get_requirements(IParams&) const override;
    void set_classifier(const IClassifier&) override;
    void set_params(const IParams&) override;
    void set_requirements(const IParams&) override;

    void broke(float) override;
    void repair() override;

    void print() const override;

    IItem& operator=(const IItem&) override;
    Potion& operator=(const Potion&);

private:
    PotionClassifier _classifier;
    Params _params;
    Params _requirements;
};


#endif // POTION_H
