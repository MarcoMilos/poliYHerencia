// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>
#pragma once

class Tile
{
    int tileValue = 30;
    char tileType; // Variable para declarar el tipo de casilla en la que pueden caer los jugadores
    // metodos de clase
    public: 
        // atributos de clase de tipo publico

        // constructores
        Tile() = default; // constructor por omision
        Tile(const int &, const char &);

        // destructor
        ~Tile(); 

        // setters
        void setValue(const int tileValue);
        void setType(const char tileType);

        // getters 
        const int &getValue();
        const char &getType();

        // printTile
        virtual void print();
};

Tile::Tile(const int &tileValue, const char &tileType)
{
    this->tileValue = tileValue;
    this->tileType = tileType;
}

Tile::~Tile(){}

void Tile::setValue(const int tileValue)
{
    this->tileValue = tileValue;
}

void Tile::setType(const char tileType)
{
    this->tileType = tileType;
}

const int &Tile::getValue()
{
    return tileValue;
}

const char &Tile::getType()
{
    return tileType;
}

void Tile::print()
{
    std::cout << 'N' << getType();
}