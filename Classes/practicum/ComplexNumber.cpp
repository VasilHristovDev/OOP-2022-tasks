#include <iostream>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

ComplexNumber::ComplexNumber() {
    this->real = 0;
    this->imaginary = 0;
}

double ComplexNumber::getRealPart() {
    return this->real;
}

double ComplexNumber::getImaginaryPart() {
    return this->imaginary;
}
void ComplexNumber::setRealPart(double number) {
    this->real = number;
}
void ComplexNumber::setImaginaryPart(double number) {
    this->imaginary = number;
}
void ComplexNumber::printComplexNumber() {
    std::cout << this->real << " + " << this->imaginary << "i" << std::endl;
}

void ComplexNumber::readComplexNumber() {
    std::cout << "Enter real part:";
    std::cin >> this->real;
    std::cout << "Enter imaginary part:";
    std::cin >> this->imaginary;
}

void ComplexNumber::add(ComplexNumber number) {
    this->real += number.getRealPart();
    this->imaginary += number.getImaginaryPart();
}

void ComplexNumber::subtract(ComplexNumber number) {
    this->real -= number.getRealPart();
    this->imaginary -= number.getImaginaryPart();
}
void ComplexNumber::multiplyBy(ComplexNumber number) {
    this->real = this->real * number.getRealPart() - this->imaginary * number.getImaginaryPart();
    this->imaginary = this->real * number.getImaginaryPart() + this->imaginary * number.getRealPart();
}
void ComplexNumber::divideBy(ComplexNumber number) {
    this->real = this->real * number.getRealPart() + this->imaginary * number.getImaginaryPart() /
            (number.getRealPart() * number.getRealPart() + number.getImaginaryPart() * number.getImaginaryPart());
    this->imaginary = this->imaginary * number.getRealPart() - this->real * number.getImaginaryPart() /
            (number.getRealPart() * number.getRealPart() + number.getImaginaryPart() * number.getImaginaryPart());
}
