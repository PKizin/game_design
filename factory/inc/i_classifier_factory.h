#ifndef I_CLASSIFIER_FACTORY_H
#define I_CLASSIFIER_FACTORY_H

#include "i_classifier.h"


class IClassifierFactory {
public:
    virtual void build_classifier(IClassifier&) const = 0;

protected:
    IClassifierFactory() { }
    virtual ~IClassifierFactory() { }
};


#endif // I_CLASSIFIER_FACTORY_H
