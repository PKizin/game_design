#ifndef I_CLASSIFIER_H
#define I_CLASSIFIER_H

#include "i_class_classifier.h"
#include "i_type_classifier.h"
#include "i_material_classifier.h"
#include "i_property_classifier.h"


class IClassifier : public IClassClassifier, public ITypeClassifier, public IMaterialClassifier, public IPropertyClassifier {
public:
    int get_class() const override { return 0; }
    int get_type() const override { return 0; }
    int get_material() const override { return 0; }
    int get_property1() const override { return 0; }
    void set_type(int) override { }
    void set_material(int) override { }
    void set_property1(int) override { }

protected:
    IClassifier() : IClassClassifier(), ITypeClassifier(), IMaterialClassifier(), IPropertyClassifier() { }
    virtual ~IClassifier() { }

private:
    IClassifier(const IClassifier&);
    IClassifier& operator=(const IClassifier&);
};


#endif // I_CLASSIFIER_H