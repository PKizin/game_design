#ifndef JEWERLY_CLASSIFIER_H
#define JEWERLY_CLASSIFIER_H

#include "i_classifier.h"
#include "e_item_categories.h"


class JewerlyClassifier : public IClassifier {
public:
    JewerlyClassifier();
    virtual ~JewerlyClassifier() { }

    int get_class() const override;
    int get_type() const override;
    int get_material() const override;
    void set_type(int) override;
    void set_material(int) override;

private:
    JewerlyClassifier(const JewerlyClassifier&);
    JewerlyClassifier& operator=(const JewerlyClassifier&);

    EItemClass _class;
    EJewerlyType _type;
    EJewerlyMaterial _material;
};


#endif // JEWERLY_CLASSIFIER_H