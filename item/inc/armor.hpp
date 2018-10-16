#ifndef ARMOR_H
#define ARMOR_H

#include "i_item.hpp"
#include "armor_classifier.hpp"
#include "params.hpp"


class Armor : public IItem {
public:
    Armor() { }
    Armor(const IClassifier&, const IParams&, const IParams&);
    virtual ~Armor() { }

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
    Armor& operator=(const Armor&);

private:
    ArmorClassifier _classifier;
    Params _params;
    Params _requirements;
};


#endif // ARMOR_H
