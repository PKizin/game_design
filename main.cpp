#include <iostream>
#include "human_classifier.h"
#include "armor_classifier.h"
#include "i_classifier.h"
using namespace std;

int main() {
    IClassifier* cl = new HumanClassifier();
    delete cl;
    cout << "1" << endl;
    return 0;
}