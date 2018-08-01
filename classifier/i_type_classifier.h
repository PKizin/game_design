#ifndef I_TYPE_CLASSIFIER_H
#define I_TYPE_CLASSIFIER_H


class ITypeClassifier {
public:
    virtual int get_type() const = 0;
    virtual void set_type(int) = 0;

protected:
    ITypeClassifier() { }
    virtual ~ITypeClassifier() { }

private:
    ITypeClassifier(const ITypeClassifier&);
    ITypeClassifier& operator=(const ITypeClassifier&);
};

#endif // I_TYPE_CLASSIFIER_H
