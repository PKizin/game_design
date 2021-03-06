#ifndef I_CLASSIFIER_HPP
#define I_CLASSIFIER_HPP

#include "i_class_classifier.hpp"
#include "i_type_classifier.hpp"
#include "i_material_classifier.hpp"
#include "i_property_classifier.hpp"

#include <iostream>
#include <typeinfo>


class IClassifier : public IClassClassifier, public ITypeClassifier, public IMaterialClassifier, public IPropertyClassifier {
public:
    virtual int get_class() const { return 0; }
    virtual int get_type() const { return 0; }
    virtual int get_material() const { return 0; }
    virtual int get_property1() const { return 0; }
    virtual void set_type(int) { }
    virtual void set_material(int) { }
    virtual void set_property1(int) { }

    virtual IClassifier& operator=(const IClassifier&) { return *this; }

protected:
    IClassifier() { }
    IClassifier(const IClassifier&) { }
    virtual ~IClassifier() { }
};


#endif // I_CLASSIFIER_HPP
