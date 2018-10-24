#ifndef ARMOR_CLASSIFIER_HPP
#define ARMOR_CLASSIFIER_HPP

#include "i_classifier.hpp"
#include "e_item_categories.hpp"


class ArmorClassifier : public IClassifier {
public:
    ArmorClassifier();
    ArmorClassifier(ArmorType, ArmorMaterial); 
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
    ItemClass _class;
    ArmorType _type;
    ArmorMaterial _material;
};


#endif // ARMOR_CLASSIFIER_HPP

