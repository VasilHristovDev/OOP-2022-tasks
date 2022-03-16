#ifndef OOP_2022_TASKS_CAR_H
#define OOP_2022_TASKS_CAR_H

class Car {
private:
    char licensePlate[8];
    char brand[20];
    char color[20];
    int doorsCount;

public:
    Car();

    Car(const char *licensePlate, const char *brand, const char *color, const int numberDoors);

    char *getLicensePlate() const;

    char *getBrand() const;

    char *getColor() const;

    int getDoorsCount() const;

    void setLicensePlate(const char *licensePlate);

    void setBrand(const char *brand);

    void setColor(const char *color);

    void setDoorsCount(int doorsCount);

    void print();

};

#endif //OOP_2022_TASKS_CAR_H
