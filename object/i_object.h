#ifndef I_OBJECT_H
#define I_OBJECT_H

#include "i_classifier.h"
#include "i_params.h"


class IObject {
public:
    virtual ~IObject() { }

    virtual IClassifier get_classifier() const = 0;
    virtual IParams get_params() const = 0;
    virtual void set_classifier(const IClassifier&) = 0;
    virtual void set_params(const IParams&) = 0;

protected:
    IObject() { }
};


#endif // I_OBJECT_H
