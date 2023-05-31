// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#pragma once

class Person
{
    // atributos de clase 
    std::string name;
    // metodos de clase
    public:
        // constructores
        Person() = default; // constructor por omision
        Person(const std::string &name) : name(name) {};

        // destructor
        ~Person();

        // setter
        void setName(std::string);

        // getter
        std::string getName();
};

Person::~Person() {}

void Person::setName(std::string name)
{
    this->name = name;
}

std::string Person::getName()
{
    return name;
}