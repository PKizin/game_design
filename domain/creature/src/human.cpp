#include "human.hpp"


Human::Human() {
}

Human::~Human() {
}

void Human::move() {
}

void Human::hit() {
}

void Human::loot() {
}

void Human::use() {
}

void Human::set_target(const ICreature& target) {
}

bool Human::search(ICreature& target) {
    return false;
}

void Human::set_use_item(const IItem& item) {
}

void Human::get_classifier(IClassifier& cla) const {
}

void Human::get_params(IParams& par) const {
}

void Human::set_classifier(const IClassifier& cla) {
}

void Human::set_params(const IParams& par) {
}

void Human::get_move_strategy(IMoveStrategy& move_str) const {
}

void Human::get_hit_strategy(IHitStrategy& hit_str) const {
}

void Human::set_move_strategy(const IMoveStrategy& move_str) {
}

void Human::set_hit_strategy(const IHitStrategy& hit_str) {
}

void Human::get_body(IItemContainer& body) const {
}

void Human::get_inventory(IItemContainer& inv) const {
}

void Human::set_body(const IItemContainer& body) {
}

void Human::set_inventory(const IItemContainer& inv) {
}
