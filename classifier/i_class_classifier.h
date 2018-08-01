#ifndef I_CLASS_CLASSIFIER_H
#define I_CLASS_CLASSIFIER_H


class IClassClassifier {
public:
    virtual int get_class() const = 0;

protected:
    IClassClassifier() { }
    virtual ~IClassClassifier() { }

private:
    IClassClassifier(const IClassClassifier&);
    IClassClassifier& operator=(const IClassClassifier&);
};

#endif // I_CLASS_CLASSIFIER_H
