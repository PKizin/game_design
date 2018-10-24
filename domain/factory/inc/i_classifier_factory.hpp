#ifndef I_CLASSIFIER_FACTORY_HPP
#define I_CLASSIFIER_FACTORY_HPP

#include "i_classifier.hpp"


class IClassifierFactory {
public:
    virtual void build_classifier(IClassifier&) const = 0;

protected:
    IClassifierFactory() { }
    virtual ~IClassifierFactory() { }
};


#endif // I_CLASSIFIER_FACTORY_HPP
