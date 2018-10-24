#ifndef JEWERLY_CLASSIFIER_HPP
#define JEWERLY_CLASSIFIER_HPP

#include "i_classifier.hpp"
#include "e_item_categories.hpp"


class JewerlyClassifier : public IClassifier {
public:
    JewerlyClassifier();
    JewerlyClassifier(const JewerlyClassifier&);
    virtual ~JewerlyClassifier() { }

    int get_class() const override;
    int get_type() const override;
    int get_material() const override;
    void set_type(int) override;
    void set_material(int) override;

    JewerlyClassifier& operator=(const JewerlyClassifier&);

private:
    ItemClass _class;
    JewerlyType _type;
    JewerlyMaterial _material;
};


#endif // JEWERLY_CLASSIFIER_HPP
