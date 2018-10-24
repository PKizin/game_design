#ifndef I_OBJECT_HPP
#define I_OBJECT_HPP

#include "i_classifier.hpp"
#include "i_params.hpp"


class IObject {
public:
    virtual void get_classifier(IClassifier&) const = 0;
    virtual void get_params(IParams&) const = 0;
    virtual void set_classifier(const IClassifier&) = 0;
    virtual void set_params(const IParams&) = 0;

protected:
    IObject() { }
    virtual ~IObject() { }
};


#endif // I_OBJECT_HPP
