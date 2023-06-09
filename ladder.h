// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include "tile.h"
#pragma once

class Ladder : public Tile
{
    public:
        // constructores
        Ladder() = default; // constructor por omision
        // constructor de formato inline para inicializar los dos atributos de la clase padre Tile
        Ladder(const int &tileValue, const char &tileType) : Tile(tileValue, tileType) {}

        // destructor
        ~Ladder(){};
};