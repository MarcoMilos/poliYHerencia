// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <stdlib.h>
#include <time.h>
#pragma once

// recomendado por Antonio Marbán
class Dice
{
    int number;
    public:
        Dice();
        ~Dice();
        int getNumber();
        void setNumber(int);
        void roll();
        int customRoll(int, int); 
};

Dice::Dice()
{
    number = 0;
}

Dice::~Dice(){}

int Dice::getNumber()
{
    return number;
}

void Dice::setNumber(int num)
{
    number = num;
}

void Dice::roll()
{
    // Selecciona un numero random de 0 a 5 (0:6) y le agrega 1, volviéndolo en un número random de 1 a 6
    number = 1 + rand() % 6;
}

int Dice::customRoll(int min, int max)
{
    return min + rand() % max;
}