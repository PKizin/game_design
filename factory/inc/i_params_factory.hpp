#ifndef I_PARAMS_FACTORY_H
#define I_PARAMS_FACTORY_H

#include "i_params.hpp"
#include "i_classifier.hpp"


class IParamsFactory {
public:
    virtual void build_params(const IClassifier&, IParams&) const = 0;

protected:
    IParamsFactory() { }
    virtual ~IParamsFactory() { }
};


#endif // I_PARAMS_FACTORY_H