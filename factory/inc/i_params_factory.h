#ifndef I_PARAMS_FACTORY_H
#define I_PARAMS_FACTORY_H

#include "i_params.h"


class IParamsFactory {
public:
    virtual void build_params(IParams&) = 0;

protected:
    IParamsFactory() { }
    virtual ~IParamsFactory() { }
};


#endif // I_PARAMS_FACTORY_H
