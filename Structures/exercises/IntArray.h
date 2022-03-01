#pragma once
#include <iostream>

struct IntArray {
    const int CAPACITY = 20;

    int elements[20] {};
    int size;
    public: IntArray()
    {
        size = 0;
    }
    void add(int number)
    {
        elements[size++] = number;
    }
    int getSize()
    {
        return size;
    }
};

void addElemToArray(IntArray &array, int number)
{
    if(array.size + 1 < array.CAPACITY)
    {
        array.elements[array.size++] = number;
    }
    else
    {
        std::cerr<<"ERROR"<<std::endl;
        return;
    }
}

void removeElemFromArray(IntArray &array, int index)
{
    if(array.size > 0 && index >= 0 && index < array.size)
    {
        for (int i = index; i < array.size; ++i)
        {
            array.elements[i] = array.elements[i + 1];
        }
        array.size--;
    }
    else
    {
        std::cerr<<"ERROR"<<std::endl;
        return;
    }
}

int getArraySize(IntArray &array)
{
    return array.size;
}

int getArrayElem(IntArray &array, int index)
{
    if(index < array.size && index >=0)
    {
        return array.elements[index];
    }
    else
    {
        std::cerr<<"ERROR"<<std::endl;
        return -1;
    }
}

void testIntArray()
{
    IntArray array;
    addElemToArray(array, 4);
    array.add(5);
    for(int i = 0; i < array.getSize(); i++) {
        std::cout<<getArrayElem(array, i)<<" ";
    }
    //трябва да изведе: “4 5 ”
    removeElemFromArray(array, 0);
    std::cout<<getArraySize(array)<<std::endl; //трябва да изведе 1
    std::cout<<getArrayElem(array, 0)<<std::endl; //трябва да изведе 5
}