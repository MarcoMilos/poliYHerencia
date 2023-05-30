// Marco & Alejandro Miloslavich Airola (A01424280, A01424120)
// 29-05-2023
// Polimorfismo y Herencia - POO

#include <cstdlib>
#include <string>
#pragma once

class Match
{
    // atributos privados de la clase
    int currentPlayer = 1; // establece que el primero en jugar es el Player1
    int turnCount = 1; // establece la cuenta de turnos en 1 al iniciar el juego

    // metodos de la clase
    public:
        // constructores
        Match() = default; // constructor por omision
        Match(const int &currentPlayer, const int &turnCount);

        // destructor
        ~Match();

        
};

