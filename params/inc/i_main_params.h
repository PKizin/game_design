#ifndef I_MAIN_PARAMS_H
#define I_MAIN_PARAMS_H

#include "e_params_categories.h"


class IMainParams {
public:
    virtual float get_main_param(EMainParam) const = 0;
    virtual void set_main_param(EMainParam, float) = 0;

protected:
    IMainParams() { }
    virtual ~IMainParams() { }

private:
    IMainParams(const IMainParams&);
    IMainParams& operator=(const IMainParams&);
};


#endif // I_MAIN_PARAMS_H
