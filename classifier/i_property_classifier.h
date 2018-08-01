#ifndef I_PROPERTY_CLASSIFIER_H
#define I_PROPERTY_CLASSIFIER_H


class IPropertyClassifier {
public:
    virtual int get_property1() const = 0;
    virtual void set_property1(int) = 0;

protected:
    IPropertyClassifier() { }
    virtual ~IPropertyClassifier() { }

private:
    IPropertyClassifier(const IPropertyClassifier&);
    IPropertyClassifier& operator=(const IPropertyClassifier&);
};

#endif // I_PROPERTY_CLASSIFIER_H
