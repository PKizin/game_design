#ifndef WEAPON_CLASSIFIER_H
#define WEAPON_CLASSIFIER_H

#include "i_classifier.h"
#include "e_item_categories.h"


class WeaponClassifier : public IClassifier {
public:
    WeaponClassifier();
    WeaponClassifier(const WeaponClassifier&);
    virtual ~WeaponClassifier() { }

    int get_class() const override;
    int get_type() const override;
    int get_material() const override;
    int get_property1() const override;
    void set_type(int) override;
    void set_material(int) override;
    void set_property1(int) override;

    IClassifier& operator=(const IClassifier&) override;
    WeaponClassifier& operator=(const WeaponClassifier&);

private:
    EItemClass _class;
    EWeaponType _type;
    EWeaponMaterial _material;
    EWeaponProperty1 _property1;
};


#endif // WEAPON_CLASSIFIER_H
