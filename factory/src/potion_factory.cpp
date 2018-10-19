#include "potion_factory.hpp"
#include "potion_classifier.hpp"
#include "potion.hpp"
#include "params.hpp"
#include "randomizer.hpp"


void PotionFactory::build_item(IItem& item) const {
    /*PotionClassifier cla;
    build_classifier(cla);

    Params par;
    build_params(cla, par);
    correct_params(par);

    Params req;
    build_params(cla, req);
    correct_requirements(req);

    item = Potion(cla, par, req);*/
}

void PotionFactory::build_classifier(IClassifier& classifier) const {
}

void PotionFactory::build_params(const IClassifier& classifier, IParams& params) const {
}

