// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#pragma once

class Tile
{
    int tileValue;
    char tileType; // Variable para declarar el tipo de casilla en la que pueden caer los jugadores
    // metodos de clase
    public: 
        // atributos de clase de tipo publico

        // constructores
        Tile() = default; // constructor por omision
        Tile(const int &, const char &) : tileType(tileType), tileValue(tileValue){};

        // destructor
        ~Tile(); 

        // setters
        void setValue(int);
        void setType(char);

        // getters 
        int getValue();
        char getType();

        // printTile
        void print();
};

Tile::~Tile(){}

void Tile::setValue(const int tileValue)
{
    this->tileValue = tileValue;
}

void Tile::setType(const char tileType)
{
    this->tileType = tileType;
}

int Tile::getValue()
{
    return tileValue;
}

char Tile::getType()
{
    return tileType;
}

void Tile::print()
{
    std::cout << tileValue << tileType << getType();
}