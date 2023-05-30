// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <cstdlib> // sirve para llamar a la funcion rand()
#pragma once

class Dice
{
    public:
        static int roll()
        {
            return rand() % 6 + 1; // genera un número aleatorio entre 1 y 6
        }
};