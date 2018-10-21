#ifndef I_TYPE_CLASSIFIER_H
#define I_TYPE_CLASSIFIER_H


class ITypeClassifier {
public:
    virtual int get_type() const = 0;
    virtual void set_type(int) = 0;

protected:
    ITypeClassifier() { }
    virtual ~ITypeClassifier() { }
};

#endif // I_TYPE_CLASSIFIER_H
