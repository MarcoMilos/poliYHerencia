// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <iostream>

class Tile
{
    // atributos privados de la clase
    int tileValue = 30;
    // metodos de clase
    public: 
        // constructores
        Tile() = default; // constructor por omision
        Tile(const int &);

        // destructor
        ~Tile(); 

        // setters
        void setValue(const int tileValue);

        // getters 
        const int &getValue();
};

Tile::Tile(const int &tileValue)
{
    this->tileValue = tileValue;
}

Tile::~Tile(){}

void Tile::setValue(const int tileValue)
{
    this->tileValue = tileValue;
}

const int &Tile::getValue()
{
    return tileValue;
}