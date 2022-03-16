#include "Intersection.h"
#include <cstring>
#include <string>
#include <iostream>

const std::string directions [4] {"east", "west", "north", "south"};


Intersection::Intersection() {
    this->currentDirection = directions[this->currentDirectionIndex];
    this->duration = 0;
}

Intersection::Intersection(std::string initDirection, int duration) {
    for (int i = 0; i < 4; ++i) {
        if(initDirection == directions[i])
        {
            this->currentDirection  = initDirection;
            this->currentDirectionIndex = i;
        }
    }

    this->duration = duration;
}

void Intersection::add(Car car, std::string direction) {
    switch (direction) {
        case "west":
            this->addWest(car);
            break;
        case "east":
            this->addEast(car);
            break;
        case "south":
            this->addSouth(car);
            break;
        case "north":
            this->addNorth(car);
            break;
        default:
            std::cerr<<"Invalid direction entered!";
            break;
    }
}

void Intersection::addNorth(Car car) {
    this->carsFromNorth[this->numberOfCarsNorth] = car;
    this->incrementNorth();
}
void Intersection::incrementNorth() {
    this->numberOfCarsNorth++;
}
void Intersection::decrementNorth() {
    this->numberOfCarsNorth--;
}

void Intersection::addSouth(Car car) {
    this->carsFromSouth[this->numberOfCarsSouth] = car;
    this->incrementSouth();
}
void Intersection::incrementSouth() {
    this->numberOfCarsSouth++;
}
void Intersection::decrementSouth() {
    this->numberOfCarsSouth--;
}

void Intersection::addEast(Car car)  {
    this->carsFromEast[this->numberOfCarsEast] = car;
    this->incrementEast();
}
void Intersection::incrementEast() {
    this->numberOfCarsEast++;
}
void Intersection::decrementEast() {
    this->numberOfCarsEast--;
}
void Intersection::addWest(Car car) {
    this->carsFromWest[this->numberOfCarsWest] = car;
    this->incrementWest();
}
void Intersection::incrementWest() {
    this->numberOfCarsWest++;
}
void Intersection::decrementWest() {
    this->numberOfCarsWest--;
}

void Intersection::tick() {
    std::cout<<"BEFORE:"<<std::endl;
    this->printEast();
    this->printWest();
    this->printNorth();
    this->printSouth();
    this->reduceFromCurrentDirection();
    std::cout<<"AFTER:"<<std::endl;
    this->printEast();
    this->printWest();
    this->printNorth();
    this->printSouth();
}
void Intersection::printEast() {
    if(this->numberOfCarsEast == 0)
    {
        std::cout<<"------EMPTY------"<<std::endl;
    }
    else
    {
        for (int i = 1; i <= numberOfCarsEast ; ++i) {
            std::cout<<i<<". "<<this->carsFromEast[i-1].getBrand()<<std::endl;
        }
    }
}

void Intersection::printWest() {
    if(this->numberOfCarsWest == 0)
    {
        std::cout<<"------EMPTY------"<<std::endl;
    }
    else
    {
        for (int i = 1; i <= numberOfCarsWest ; ++i) {
            std::cout<<i<<". "<<this->carsFromWest[i-1].getBrand()<<std::endl;
        }
    }
}

void Intersection::printNorth() {
    if(this->numberOfCarsNorth == 0)
    {
        std::cout<<"------EMPTY------"<<std::endl;
    }
    else
    {
        for (int i = 1; i <= numberOfCarsNorth ; ++i) {
            std::cout<<i<<". "<<this->carsFromNorth[i-1].getBrand()<<std::endl;
        }
    }
}

void Intersection::printSouth() {
    if(this->numberOfCarsSouth == 0)
    {
        std::cout<<"------EMPTY------"<<std::endl;
    }
    else
    {
        for (int i = 1; i <= numberOfCarsSouth ; ++i) {
            std::cout<<i<<". "<<this->carsFromSouth[i-1].getBrand()<<std::endl;
        }
    }
}

void Intersection::reduceCarsFromCurrentDirection() {
    std::string currentDir = this->getCurrentDirection();

    switch (currentDir) {
        case "east":
            this->removeCarsFromEast(this->getDuration());
            break;
        case "west":
            this->removeCarsFromWest(this->getDuration());
            break;
        case "north":
            this->removeCarsFromNorth(this->getDuration());
            break;
        case "south":
            this->removeCarsFromSouth(this->getDuration());
            break;
        default:
            break;
        this->changeDirection();

    }
}

const * char Intersection::getCurrentDirection() const {
    return this->currentDirection;
}

void Intersection::removeCarsFromEast(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsEast ; ++i) {
        this->carsFromEast[i] = this->carsFromEast[i + numberOfCars];
    }
    for (int i = 0; i < this->duration ; ++i) {
        this->decrementEast()
    }
}

void Intersection::removeCarsFromWest(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsWest ; ++i) {
        this->carsFromWest[i] = this->carsFromWest[i + numberOfCars];
    }
    for (int i = 0; i < this->duration ; ++i) {
        this->decrementWest()
    }
}

void Intersection::removeCarsFromNorth(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsNorth ; ++i) {
        this->carsFromNorth[i] = this->carsFromNorth[i + numberOfCars];
    }
    for (int i = 0; i < this->duration ; ++i) {
        this->decrementNorth()
    }
}

void Intersection::removeCarsFromSouth(int numberOfCars) {
    for (int i = 0; i < this->numberOfCarsWest ; ++i) {
        this->carsFromSouth[i] = this->carsFromSouth[i + numberOfCars];
    }
    for (int i = 0; i < this->duration ; ++i) {
        this->decrementSouth()
    }
}
void Intersection::changeDirection() {
    if(this->currentDirectionIndex == 3)
    {
        this->currentDirectionIndex = 0;
        delete [] this->currentDirection;
        this->currentDirection = new char [directions[currentDirectionIndex].size()];
        strcpy_s(this->currentDirection, directions[this->currentDirectionIndex]);
    }
    else
    {
        this->currentDirectionIndex++;
        delete [] this->currentDirection;
        this->currentDirection = new char [directions[currentDirectionIndex].size()];
        strcpy_s(this->currentDirection, directions[this->currentDirectionIndex]);
    }

}

