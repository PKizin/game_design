#ifndef MONSTER_CLASSIFIER_HPP
#define MONSTER_CLASSIFIER_HPP

#include "i_classifier.hpp"
#include "e_creature_categories.hpp"


class MonsterClassifier : public IClassifier {
public:
    MonsterClassifier();
    MonsterClassifier(const MonsterClassifier&);
    virtual ~MonsterClassifier() { }

    int get_class() const override;
    int get_type() const override;
    void set_type(int) override;

    MonsterClassifier& operator=(const MonsterClassifier&);

private:
    CreatureClass _class;
    MonsterType _type;
};


#endif // MONSTER_CLASSIFIER_HPP
