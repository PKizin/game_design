#ifndef I_TYPE_CLASSIFIER_HPP
#define I_TYPE_CLASSIFIER_HPP


class ITypeClassifier {
public:
    virtual int get_type() const = 0;
    virtual void set_type(int) = 0;

protected:
    ITypeClassifier() { }
    virtual ~ITypeClassifier() { }
};

#endif // I_TYPE_CLASSIFIER_HPP
