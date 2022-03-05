#pragma once

class ComplexNumber {
private:
    double real;
    double imaginary;
public:
    ComplexNumber();

    ComplexNumber(double real, double imaginary);

    double getRealPart();

    double getImaginaryPart();

    void setRealPart(double number);

    void setImaginaryPart(double number);

    void readComplexNumber();

    void printComplexNumber();

    void add(ComplexNumber number);

    void subtract(ComplexNumber number);

    void multiplyBy(ComplexNumber number);

    void divideBy(ComplexNumber number);

};



