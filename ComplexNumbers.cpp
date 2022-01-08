#include "ComplexNumbers.h"

void ComplexNumber::setRealPart(ld r){realPart = r;}
void ComplexNumber::setImaginaryPart(ld i){imaginaryPart = i;}
void ComplexNumber::showNumber(){std::cout.precision(1); std::cout << std::fixed << realPart << (imaginaryPart >= 0 ? "+" : "") << imaginaryPart << "i";}

ld ComplexNumber::length(){return sqrt(realPart * realPart + imaginaryPart * imaginaryPart);}

ComplexNumber multiplicativeInverse(ComplexNumber z){
    ld sq = pow(z.getRealPart(), 2) + pow(z.getImaginaryPart(), 2);
    if(sq == 0) throw std::logic_error("You can't divide by 0");
    ComplexNumber inverse(z.getRealPart() / sq, (-1) * z.getImaginaryPart() / sq);
    return inverse;
}

ComplexNumber multiplyComplexNumber(ComplexNumber z, ld alpha){
    z.setRealPart(z.getRealPart() * alpha);
    z.setImaginaryPart(z.getImaginaryPart() * alpha);
    return z;
}

ComplexNumber complexConjugate(ComplexNumber z){
    ComplexNumber conjugate(z.getRealPart(), (-1) * z.getImaginaryPart());
    return conjugate;
}
/*
ComplexNumber complexOpposite(ComplexNumber z){

}*/
ld ComplexNumber::getRealPart(){
    return realPart;
}

ld ComplexNumber::getImaginaryPart(){
    return imaginaryPart;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber z){
    ComplexNumber z1(realPart + z.getRealPart(), imaginaryPart + z.getImaginaryPart());
    return z1;
}
ComplexNumber ComplexNumber::operator-(ComplexNumber z){
    ComplexNumber z1(realPart - z.getRealPart(), imaginaryPart - z.getImaginaryPart());
    return z1;
}
ComplexNumber ComplexNumber::operator*(ComplexNumber z){//come again
    ComplexNumber result(realPart * z.getRealPart() - imaginaryPart * z.getImaginaryPart(),
                         realPart * z.getImaginaryPart() + imaginaryPart * z.getRealPart());
    return result;
}
ComplexNumber ComplexNumber::operator/(ComplexNumber z){return (*this) * multiplicativeInverse(z);}
bool ComplexNumber::operator==(ComplexNumber z){return (realPart == z.getRealPart()) && (imaginaryPart == z.getImaginaryPart());}
bool ComplexNumber::operator!=(ComplexNumber z){return (realPart != z.getRealPart() || imaginaryPart != z.getImaginaryPart());}
void ComplexNumber::operator=(ComplexNumber z){realPart = z.getRealPart(); imaginaryPart = z.getImaginaryPart();}
ComplexNumber ComplexNumber::operator+=(ComplexNumber z){
    ComplexNumber k(realPart + z.getRealPart(), imaginaryPart + z.getImaginaryPart());
    return k;
}
ComplexNumber ComplexNumber::operator-=(ComplexNumber z){
    ComplexNumber k(realPart - z.getRealPart(), imaginaryPart - z.getImaginaryPart());
    return k;
}