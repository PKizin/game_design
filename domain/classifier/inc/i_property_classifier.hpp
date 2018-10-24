#ifndef I_PROPERTY_CLASSIFIER_HPP
#define I_PROPERTY_CLASSIFIER_HPP


class IPropertyClassifier {
public:
    virtual int get_property1() const = 0;
    virtual void set_property1(int) = 0;

protected:
    IPropertyClassifier() { }
    virtual ~IPropertyClassifier() { }
};

#endif // I_PROPERTY_CLASSIFIER_HPP
