#ifndef ARMOR_CLASSIFIER_H
#define ARMOR_CLASSIFIER_H

#include "i_classifier.h"
#include "e_item_categories.h"


class ArmorClassifier : public IClassifier {
public:
    ArmorClassifier();
    ArmorClassifier(EArmorType, EArmorMaterial); 
    ArmorClassifier(const ArmorClassifier&);
    ArmorClassifier(const IClassifier&);
    virtual ~ArmorClassifier() { }

    int get_class() const override;
    int get_type() const override;
    int get_material() const override;
    void set_type(int) override;
    void set_material(int) override;

    IClassifier& operator=(const IClassifier&) override;
    ArmorClassifier& operator=(const ArmorClassifier&);

private:
    EItemClass _class;
    EArmorType _type;
    EArmorMaterial _material;
};


#endif // ARMOR_CLASSIFIER_H

