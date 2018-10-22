#include "potion.hpp"
#include <vector>


Potion::Potion(const IClassifier& classifier, const IParams& params, const IParams& requirements) :
    IItem(),
    _classifier( classifier ),
    _params( params ),
    _requirements( requirements )
{
}


void Potion::get_classifier(IClassifier& classifier) const {
    classifier = PotionClassifier( _classifier );
}

void Potion::get_params(IParams& params) const {
    params = Params( _params );
}

void Potion::get_requirements(IParams& requirements) const {
    requirements = Params( _requirements );
}


void Potion::set_classifier(const IClassifier& classifier) {
    _classifier = PotionClassifier( classifier );
}

void Potion::set_params(const IParams& params) {
    _params = Params( params );
}

void Potion::set_requirements(const IParams& requirements) {
    _requirements = Params( requirements );
}


void Potion::broke(float damage)
{
}

void Potion::repair()
{
}


void Potion::print() const
{
    const auto& tab = '\t';
    const auto& end_line = '\n';
    const auto& end_section = "\n\n";

    const std::vector< std::string > class_tags = { "none", "weapon", "armor", "jewerly", "potion" };
    const std::vector< std::string > type_tags = { "none", "hp", "mp", "exp" };
    const std::vector< std::string > property1_tags = { "none", "small", "medium", "big" };

    const auto& hp = static_cast<int>(_params.get_life_param(ELifeParams::_hp));
    const auto& mp = static_cast<int>(_params.get_life_param(ELifeParams::_mp));
    const auto& ex = static_cast<int>(_params.get_exp_param(EExpParams::_exp));

    std::cout << end_line;
    std::cout << "+--------------+" << end_line;
    std::cout << "|     item     |" << end_line;
    std::cout << "+--------------+" << end_line;

    std::cout << "classifier:" << end_line;
    std::cout << tab << "class     : " << class_tags[ _classifier.get_class() ] << end_line;
    std::cout << tab << "type      : " << type_tags[ _classifier.get_type() ] << end_line;
    std::cout << tab << "property1 : " << property1_tags[ _classifier.get_property1() ] << end_section;

    std::cout << "params:" << end_line;
    if (hp)
        std::cout << tab << "hp : +" << hp << end_line;
    if (mp)
        std::cout << tab << "mp : +" << mp << end_line;
    if (ex)
        std::cout << tab << "exp : +" << ex << end_line;
}


IItem& Potion::operator=(const IItem& other) {
    return operator=( static_cast< const Potion& >(other) );
}

Potion& Potion::operator=(const Potion& other) {
    _classifier = other._classifier;
    _params = other._params;
    _requirements = other._requirements;
    return *this;
}