#include "human.hpp"
#include "i_move_strategy.hpp"
#include "i_hit_strategy.hpp"
#include "i_search_strategy.hpp"


Human::Human() {
}

Human::~Human() {
}


void Human::move(enum EDirection dir) {
    if (_move_strategy) {
        _move_strategy->move(*this, dir);
    }
}

void Human::hit() {
    if (_hit_strategy) {
        _hit_strategy->hit(*this);
    }
}

void Human::search() {
    if (_search_strategy) {
        _search_strategy->search(*this);
    }
}

void Human::loot() {
}

void Human::use() {
}


void Human::set_target(const ICreature& target) {
    _target = &const_cast<ICreature&>(target);
}

bool Human::has_target() {
    return (_target != nullptr);
}

void Human::set_use_item(const IItem& item) {
    _use_item = &const_cast<IItem&>(item);
}


void Human::get_classifier(IClassifier& cla) const {
}

void Human::set_classifier(const IClassifier& cla) {
}

void Human::get_params(IParams& par) const {
}

void Human::set_params(const IParams& par) {
}


void Human::get_move_strategy(IMoveStrategy& move_str) const {
}

void Human::set_move_strategy(const IMoveStrategy& move_str) {
}

void Human::get_hit_strategy(IHitStrategy& hit_str) const {
}

void Human::set_hit_strategy(const IHitStrategy& hit_str) {
}

void Human::get_search_strategy(ISearchStrategy& search_str) const {
}

void Human::set_search_strategy(const ISearchStrategy& search_str) {
}


void Human::get_body(IItemContainer& body) const {
}

void Human::set_body(const IItemContainer& body) {
}

void Human::get_inventory(IItemContainer& inv) const {
}

void Human::set_inventory(const IItemContainer& inv) {
}
