#ifndef CALGEO_COMPLEXNUMBERS_H
#define CALGEO_COMPLEXNUMBERS_H
#include "CONSTANTS.h"

class ComplexNumber {
private:
    ld realPart;
    ld imaginaryPart;
public:
    ComplexNumber(ld r, ld i){realPart = r;imaginaryPart = i;}
    ComplexNumber(){}

    void setRealPart(ld);
    void setImaginaryPart(ld);
    void showNumber();
    ld length();
    ld getRealPart();
    ld getImaginaryPart();

    ComplexNumber operator+(ComplexNumber);
    ComplexNumber operator-(ComplexNumber);
    ComplexNumber operator*(ComplexNumber);
    ComplexNumber operator/(ComplexNumber);
    ComplexNumber operator+=(ComplexNumber);
    ComplexNumber operator-=(ComplexNumber);
    bool operator==(ComplexNumber);
    bool operator!=(ComplexNumber);
    void operator=(ComplexNumber);

    vector<ComplexNumber> root(ComplexNumber);

};

ComplexNumber multiplyComplexNumber(ComplexNumber z, ld);
ComplexNumber complexConjugate(ComplexNumber);
ComplexNumber multiplicativeInverse(ComplexNumber);
//ComplexNumber complexOpposite(ComplexNumber);




#endif //CALGEO_COMPLEXNUMBERS_H
