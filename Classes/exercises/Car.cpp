#include <iostream>
#include <cstring>
#include "Car.h"

Car::Car(const char *licensePlate, const char *brand, const char *color, const int numberDoors) {
    this->setLicensePlate(licensePlate);
    this->setBrand(brand);
    this->setColor(color);
    this->setDoorsCount(numberDoors);
}

void Car::setLicensePlate(const char *_licensePlate) {
    this->licensePlate = new char[strlen(_licensePlate)];
    strcpy_s(this->licensePlate, _licensePlate);
}

void Car::setBrand(const char *_brand) {
    this->brand = new char[strlen(_brand)];
    strcpy(this->brand, _brand);
}

void Car::setColor(const char *_color) {
    this->color = new char[strlen(_color)];
    strcpy(this->color, _color);
}

void Car::setDoorsCount(int _doorsCount) {
    this->doorsCount = _doorsCount;
}

char * Car::getLicensePlate() const {
    return this->licensePlate;
}
char * Car::getBrand() const {
    return this->brand;
}
char * Car::getColor() const {
    return this->color;
}
char * Car::getDoorsCount() const {
    return this->doorsCount;
}

void Car::print() {
    std::cout<<this->color<<" "<< this->brand<<" ("<<this->licensePlate<<"), "<<this->doorsCount<<" doors";
}