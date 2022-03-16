#ifndef OOP_2022_TASKS_INTERSECTION_H
#define OOP_2022_TASKS_INTERSECTION_H

#include "Car.h"
#include <string>

class Intersection {
private:
    Car carsFromEast[10];
    unsigned numberOfCarsEast = 0;

    Car carsFromWest[10];
    unsigned numberOfCarsWest = 0;

    Car carsFromSouth[10];
    unsigned numberOfCarsSouth = 0;

    Car carsFromNorth[10];
    unsigned numberOfCarsNorth = 0;

    int duration;
    std::string currentDirection;
    int currentDirectionIndex = 0;

public:
    Intersection();

    Intersection(std::string initDirection, int duration);

    void addWest(Car car);

    void incrementWest();

    void decrementWest();

    void printWest();

    void removeCarsFromWest(int numberOfCars);

    void addEast(Car car);

    void incrementEast();

    void decrementEast();

    void printEast();

    void removeCarsFromEast(int numberOfCars);

    void addSouth(Car car);

    void incrementSouth();

    void decrementSouth();

    void printSouth();

    void removeCarsFromSouth(int numberOfCars);

    void addNorth(Car car);

    void incrementNorth();

    void decrementNorth();

    void printNorth();

    void removeCarsFromNorth(int numberOfCars);

    void reduceCarsFromCurrentDirection();

    void changeDirection();

    const std::string getCurrentDirection() const;

    void tick();

    void add(Car car, std::string direction);

};

#endif //OOP_2022_TASKS_INTERSECTION_H
