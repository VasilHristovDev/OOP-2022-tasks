#include <iostream>
#include "ComplexNumber.cpp"

ComplexNumber addTwo(ComplexNumber a, ComplexNumber b) {
    return ComplexNumber(a.getRealPart() + b.getRealPart(), a.getImaginaryPart() + b.getImaginaryPart());
}

ComplexNumber subtractTwo(ComplexNumber a, ComplexNumber b) {
    return ComplexNumber(a.getRealPart() - b.getRealPart(), a.getImaginaryPart() - b.getImaginaryPart());
}

ComplexNumber multiplyTwo(ComplexNumber a, ComplexNumber b) {
    ComplexNumber result;
    result.setRealPart(a.getRealPart() * b.getRealPart() - a.getImaginaryPart() * b.getImaginaryPart());
    result.setImaginaryPart(a.getRealPart() * b.getImaginaryPart() + a.getImaginaryPart() * b.getRealPart());
    return result;
}

ComplexNumber divideTwo(ComplexNumber a, ComplexNumber b) {
    ComplexNumber result;
    result.setRealPart(a.getRealPart() * b.getRealPart() + a.getImaginaryPart() * b.getImaginaryPart() /
        (b.getRealPart() * b.getRealPart() + b.getImaginaryPart() * b.getImaginaryPart()));
    result.setImaginaryPart(a.getImaginaryPart() * b.getRealPart() - a.getRealPart() * b.getImaginaryPart() /
        (b.getRealPart() * b.getRealPart() + b.getImaginaryPart() * b.getImaginaryPart()));
    return result;
}

int main() {
    ComplexNumber number = addTwo(ComplexNumber(1,2), ComplexNumber(1,2));
    number.printComplexNumber();
    ComplexNumber number1 = subtractTwo(ComplexNumber(2,3), ComplexNumber(1,2));
    number1.printComplexNumber();
    ComplexNumber number2 = multiplyTwo(ComplexNumber(2,3), ComplexNumber(1,2));
    number2.printComplexNumber();
    ComplexNumber number3 = divideTwo(ComplexNumber(2,3), ComplexNumber(1,2));
    number3.printComplexNumber();
}