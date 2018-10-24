#ifndef I_MATERIAL_CLASSIFIER_HPP
#define I_MATERIAL_CLASSIFIER_HPP


class IMaterialClassifier {
public:
    virtual int get_material() const = 0;
    virtual void set_material(int) = 0;

protected:
    IMaterialClassifier() { }
    virtual ~IMaterialClassifier() { }
};

#endif // I_MATERIAL_CLASSIFIER_HPP
