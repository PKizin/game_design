#ifndef I_MATERIAL_CLASSIFIER_H
#define I_MATERIAL_CLASSIFIER_H


class IMaterialClassifier {
public:
    virtual int get_material() const = 0;
    virtual void set_material(int) = 0;

protected:
    IMaterialClassifier() { }
    virtual ~IMaterialClassifier() { }

private:
    IMaterialClassifier(const IMaterialClassifier&);
    IMaterialClassifier& operator=(const IMaterialClassifier&);
};

#endif // I_MATERIAL_CLASSIFIER_H
