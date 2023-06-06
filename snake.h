// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#include <cstdlib> // sirve para llamar a la funcion rand()
#include "tile.h"
#pragma once

class Snake : public Tile
{
    public:
        // constructores
        Snake() = default; // constructor por omision
        // constructor de formato inline para inicializar los dos atributos de la clase padre Tile
        Snake(const int &tileValue, const char &tileType) : Tile(tileValue, tileType) {}

        // destructor
        ~Snake();
};

Snake::~Snake(){}
