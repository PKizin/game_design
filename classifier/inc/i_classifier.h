#ifndef I_CLASSIFIER_H
#define I_CLASSIFIER_H

#include "i_class_classifier.h"
#include "i_type_classifier.h"
#include "i_material_classifier.h"
#include "i_property_classifier.h"

#include <iostream>
#include <typeinfo>


class IClassifier : public IClassClassifier, public ITypeClassifier, public IMaterialClassifier, public IPropertyClassifier {
public:
    IClassifier() : IClassClassifier(), ITypeClassifier(), IMaterialClassifier(), IPropertyClassifier() { }
    IClassifier(const IClassifier&) : IClassifier() { }
    virtual ~IClassifier() { }

    int get_class() const override { return 0; }
    int get_type() const override { return 0; }
    int get_material() const override { return 0; }
    int get_property1() const override { return 0; }
    void set_type(int) override { }
    void set_material(int) override { }
    void set_property1(int) override { }

    // downcast IClassifier
    template<class T>
    static void copy(const IClassifier& source, const IClassifier& destination) {
        try {
            T& par1 = dynamic_cast< T& >(const_cast< IClassifier& >(source));
            T& par2 = dynamic_cast< T& >(const_cast< IClassifier& >(destination));
            par2 = par1; 
        }
        catch (std::bad_cast& bc) {
            std::cerr << "bad cast catch: " << bc.what() << std::endl;
        }
    }

    virtual void print() const { }

    virtual IClassifier& operator=(const IClassifier&) { return *this; }
};


#endif // I_CLASSIFIER_H
